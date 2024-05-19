#include "codegen_visitor.hpp"
#include "ast/translation_unit.hpp"
#include "ast/function_definition.hpp"
#include "ast/declaration.hpp"
#include "all_statements.hpp"
#include "all_expressions.hpp"

namespace nezoku {

template<class... Ts> struct VariantVisitor: Ts... { using Ts::operator()...; };
template<class... Ts> VariantVisitor(Ts...) -> VariantVisitor<Ts...>;

CodegenVisitor::CodegenVisitor(const std::string& file_name)
    : builder_(context_)
    , module_(std::make_unique<llvm::Module>(file_name, context_))
    , file_(file_name)
    , current_scope_(std::make_shared<Scope<llvm::Value*>>("global")) {}

void CodegenVisitor::visit(TranslationUnit* translation_unit) {
    for (const auto& external_declaration: translation_unit->external_declarations()) {
        std::visit(
            VariantVisitor{
                [this](Declaration* declaration) { declaration->accept_visitor(this); },
                [this](FunctionDefinition* function_definition) { function_definition->accept_visitor(this); }
            },
            external_declaration
        );
    }

    std::error_code err;
    llvm::raw_fd_ostream out_file(file_, err);

    if (!err) {
        module_->print(out_file, nullptr);
        out_file.close();
    } else {
        // TODO: Throw error.
        return;
    }
}

void CodegenVisitor::visit(Declaration* declaration) {
    // TODO: Support more types.
    auto new_var = builder_.CreateAlloca(builder_.getInt32Ty());

    // Compile initial value.
    auto init = declaration->initializer();

    if (init) {
        init->accept_visitor(this);
        auto value = latest_values_.top();
        latest_values_.pop();
        // TODO: Support more types.
        assert(value->getType() == builder_.getInt32Ty());
        builder_.CreateStore(value, new_var);
    }

    auto name = declaration->variable_name();
    current_scope_->add_value(name, new_var);
}

void CodegenVisitor::visit(FunctionDefinition* function_definition) {
    // Create a new scope for each function.
    auto func_name = function_definition->function_name();
    current_scope_ = std::make_shared<Scope<llvm::Value*>>(func_name, current_scope_);

    std::vector<llvm::Type*> arg_types;
    auto args = function_definition->parameter_list();

    for ([[maybe_unused]] const auto& arg: args) {
        // TODO: Support more types.
        arg_types.push_back(builder_.getInt32Ty());
    }

    llvm::ArrayRef<llvm::Type*> args_ref(arg_types);
    // TODO: Support more types.
    auto func_type = llvm::FunctionType::get(builder_.getInt32Ty(), args_ref, /* isVarArg */ false);
    current_function_ = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, func_name, module_.get());
    functions_.insert(std::make_pair(func_name, current_function_));

    // Create entry block.
    auto entry = generate_block(func_name + ".entry");
    builder_.SetInsertPoint(entry);

    for (size_t i = 0; i < args.size(); i++) {
        auto arg = current_function_->getArg(i);
        auto new_var = builder_.CreateAlloca(arg->getType());
        builder_.CreateStore(arg, new_var);
        current_scope_->add_value(args[i].second, new_var);
    }

    auto body = function_definition->function_body();
    body->accept_visitor(this);

    // End of the function's scope.
    current_scope_ = current_scope_->parent();
}

void CodegenVisitor::visit(CompoundStatement* compound_statement) {
    // Create a new anonymous scope.
    current_scope_ = std::make_shared<Scope<llvm::Value*>>(current_scope_);

    for (const auto& block_item: compound_statement->block_item_list()) {
        std::visit(
            VariantVisitor{
                [this](Declaration* declaration) { declaration->accept_visitor(this); },
                [this](Statement* statement) { statement->accept_visitor(this); }
            },
            block_item
        );
    }

    // Return to the parent scope.
    current_scope_ = current_scope_->parent();
}

void CodegenVisitor::visit(ExpressionStatement* expression_statement) {
    auto expression = expression_statement->expression();

    if (expression) {
        expression->accept_visitor(this);
    }
}

void CodegenVisitor::visit(ReturnStatement* return_statement) {
    auto ret_expr = return_statement->expression();

    if (ret_expr) {
        ret_expr->accept_visitor(this);
    } else {
        builder_.CreateRetVoid();
        return;
    }

    auto ret_value = latest_values_.top();
    latest_values_.pop();
    builder_.CreateRet(ret_value);
}

void CodegenVisitor::visit([[maybe_unused]] ContinueStatement* continue_statement) {
    if (cond_block_) {
        // TODO: Support dead code after continue;
        builder_.CreateBr(cond_block_);
    } else {
        // TODO: Throw error.
    }
}

void CodegenVisitor::visit([[maybe_unused]] BreakStatement* break_statement) {
    if (out_block_) {
        // TODO: Support dead code after break;
        builder_.CreateBr(out_block_);
    } else {
        // TODO: Throw error.
    }
}

void CodegenVisitor::visit(SelectionStatement* selection_statement) {
    // Create basic block for if operator parts.
    auto then_block = generate_block("if.true");
    llvm::BasicBlock* else_block = nullptr;
    auto out_block = generate_block("if.out");

    // Compile selection condition.
    auto condition = selection_statement->if_expression();
    condition->accept_visitor(this);
    auto condition_value = latest_values_.top();
    latest_values_.pop();
    assert(condition_value->getType() == builder_.getInt1Ty());

    auto if_body = selection_statement->then_statement();
    auto else_body = selection_statement->else_statement();

    if (else_body) {
        else_block = generate_block("if.false");
        builder_.CreateCondBr(condition_value, then_block, else_block);
    } else {
        builder_.CreateCondBr(condition_value, then_block, out_block);
    }

    // Compile main branch.
    auto br_out = [this, out_block](llvm::BasicBlock* src_block) {
        // TODO: Support empty out blocks.
        if (!src_block->getTerminator()) {
            builder_.SetInsertPoint(src_block);
            builder_.CreateBr(out_block);
        }
    };

    builder_.SetInsertPoint(then_block);
    if_body->accept_visitor(this);
    br_out(then_block);

    // Compile alternative branch.
    if (else_body) {
        builder_.SetInsertPoint(else_block);
        else_body->accept_visitor(this);
        br_out(else_block);
    }

    // Go out from the selection statement.
    builder_.SetInsertPoint(out_block);
}

void CodegenVisitor::visit(IterationStatement* iteration_statement) {
    // Create basic block for cycle parts.
    auto cond_block = generate_block("while.condition");
    auto iter_block = generate_block("while.body");
    auto out_block = generate_block("while.out");
    builder_.CreateBr(cond_block);

    // Save previous iteration frame.
    auto prev_cond = cond_block_;
    auto prev_out = out_block_;
    cond_block_ = cond_block;
    out_block_ = out_block;

    // Compile cycle condition.
    builder_.SetInsertPoint(cond_block);
    auto condition = iteration_statement->condition();
    condition->accept_visitor(this);
    auto condition_value = latest_values_.top();
    latest_values_.pop();
    assert(condition_value->getType() == builder_.getInt1Ty());
    builder_.CreateCondBr(condition_value, iter_block, out_block);

    // Compile cycle body.
    builder_.SetInsertPoint(iter_block);
    auto body = iteration_statement->body();
    body->accept_visitor(this);
    builder_.CreateBr(cond_block);

    // Reset iteration frame.
    builder_.SetInsertPoint(out_block);
    cond_block_ = prev_cond;
    out_block_ = prev_out;
}

void CodegenVisitor::visit(AssignmentExpression* assignment_expression) {
    auto left_expr = assignment_expression->left_expression();
    auto id_expr = dynamic_cast<IdentifierExpression*>(left_expr);

    // Type checking for the left side to be an lvalue.
    if (!id_expr) {
        // TODO: Throw error.
        return;
    }

    auto name = id_expr->identifier();
    auto variable_opt = scope_find_value(name, current_scope_);

    if (!variable_opt) {
        // TODO: Throw error.
        return;
    }

    auto right_expr = assignment_expression->right_expression();
    right_expr->accept_visitor(this);
    auto value = latest_values_.top();
    latest_values_.pop();

    auto variable = variable_opt.value();
    // TODO: Support different assignment operations.
    builder_.CreateStore(value, variable);
    // TODO: Support more types.
    auto new_value = builder_.CreateLoad(builder_.getInt32Ty(), variable);
    // TODO: Detect and discard (pop) unused expressions.
    latest_values_.push(new_value);
}

void CodegenVisitor::visit(LorExpression* logical_or_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateLogicalOr(lhs, rhs);
    };
    visit_binary_op(logical_or_expression, call);
}

void CodegenVisitor::visit(LandExpression* logical_and_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateLogicalAnd(lhs, rhs);
    };
    visit_binary_op(logical_and_expression, call);
}

void CodegenVisitor::visit(OrExpression* inclusive_or_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateOr(lhs, rhs);
    };
    visit_binary_op(inclusive_or_expression, call);
}

void CodegenVisitor::visit(XorExpression* exclusive_or_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateXor(lhs, rhs);
    };
    visit_binary_op(exclusive_or_expression, call);
}

void CodegenVisitor::visit(AndExpression* and_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateAnd(lhs, rhs);
    };
    visit_binary_op(and_expression, call);
}

void CodegenVisitor::visit(EqExpression* eq_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateICmpEQ(lhs, rhs);
    };
    visit_binary_op(eq_expression, call);
}

void CodegenVisitor::visit(NeqExpression* neq_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateICmpNE(lhs, rhs);
    };
    visit_binary_op(neq_expression, call);
}

void CodegenVisitor::visit(LessExpression* less_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateICmpSLT(lhs, rhs);
    };
    visit_binary_op(less_expression, call);
}

void CodegenVisitor::visit(GreaterExpression* greater_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateICmpSGT(lhs, rhs);
    };
    visit_binary_op(greater_expression, call);
}

void CodegenVisitor::visit(LeqExpression* leq_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateICmpSLE(lhs, rhs);
    };
    visit_binary_op(leq_expression, call);
}

void CodegenVisitor::visit(GeqExpression* geq_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateICmpSGE(lhs, rhs);
    };
    visit_binary_op(geq_expression, call);
}

void CodegenVisitor::visit(ShlExpression* shl_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateShl(lhs, rhs);
    };
    visit_binary_op(shl_expression, call);
}

void CodegenVisitor::visit(ShrExpression* shr_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateLShr(lhs, rhs);
    };
    visit_binary_op(shr_expression, call);
}

void CodegenVisitor::visit(AddExpression* add_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateAdd(lhs, rhs);
    };
    visit_binary_op(add_expression, call);
}

void CodegenVisitor::visit(SubExpression* sub_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateSub(lhs, rhs);
    };
    visit_binary_op(sub_expression, call);
}

void CodegenVisitor::visit(MulExpression* mul_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateMul(lhs, rhs);
    };
    visit_binary_op(mul_expression, call);
}

void CodegenVisitor::visit(DivExpression* div_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateSDiv(lhs, rhs);
    };
    visit_binary_op(div_expression, call);
}

void CodegenVisitor::visit(ModExpression* mod_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        assert(lhs->getType() == builder_.getInt32Ty() && rhs->getType() == builder_.getInt32Ty());
        return builder_.CreateSRem(lhs, rhs);
    };
    visit_binary_op(mod_expression, call);
}

void CodegenVisitor::visit(FunctionCallExpression* function_call_expression) {
    // TODO: Support function pointers.
    auto left_expr = function_call_expression->function();
    auto id_expr = dynamic_cast<IdentifierExpression*>(left_expr);

    // Type checking for a function name.
    if (!id_expr) {
        // TODO: Throw error.
        return;
    }

    std::vector<llvm::Value*> args;
    auto arg_list = function_call_expression->argument_list();

    for (const auto& arg : arg_list) {
        arg->accept_visitor(this);
        auto arg_val = latest_values_.top();
        latest_values_.pop();
        args.push_back(arg_val);
    }

    auto args_ref = llvm::ArrayRef<llvm::Value*>(args);
    auto name = id_expr->identifier();
    auto found_func = functions_.find(name);

    // TODO: Clean the code here.
    if (found_func == functions_.end()) {
        if (name == "printf") {
            auto func_callee = get_printf();
            auto ret_value = builder_.CreateCall(func_callee, args_ref);
            latest_values_.push(ret_value);
        } else if (name == "scanf") {
            auto func_callee = get_scanf();
            auto ret_value = builder_.CreateCall(func_callee, args_ref);
            latest_values_.push(ret_value);
        } else {
            // TODO: Throw error.
            return;
        }
    } else {
        auto func_type = found_func->second->getFunctionType();
        auto func_callee = module_->getOrInsertFunction(name, func_type);
        auto ret_value = builder_.CreateCall(func_callee, args_ref);
        latest_values_.push(ret_value);
    }
}

void CodegenVisitor::visit(IdentifierExpression* identifier_expression) {
    auto name = identifier_expression->identifier();
    auto value_opt = scope_find_value(name, current_scope_);
    assert(value_opt);
    auto value = value_opt.value();
    // TODO: Support more types.
    auto load = builder_.CreateLoad(builder_.getInt32Ty(), value);
    latest_values_.push(load);
}

void CodegenVisitor::visit(ConstantExpression* constant_expression) {
    auto constant = constant_expression->constant();
    auto converted = std::stoll(constant);
    // TODO: Support more types.
    auto value = llvm::ConstantInt::get(builder_.getInt32Ty(), converted, /* IsSigned */ true);
    latest_values_.push(value);
}

void CodegenVisitor::visit(StringExpression* string_expression) {
    auto str = string_expression->string();
    // TODO: Handle excessive quotation marks smoother.
    str.erase(0, 1);
    str.pop_back();
    // TODO: Add support for escape sequences.
    auto value = builder_.CreateGlobalStringPtr(str + "\n");
    latest_values_.push(value);
}

llvm::FunctionCallee CodegenVisitor::get_printf() {
    auto printf_ret = builder_.getInt32Ty();
    std::vector<llvm::Type*> printf_args;
    printf_args.push_back(builder_.getInt8Ty()->getPointerTo());
    llvm::ArrayRef<llvm::Type*> args_ref(printf_args);
    auto printf_type = llvm::FunctionType::get(printf_ret, args_ref, /* IsVarArg */ true);
    return module_->getOrInsertFunction("printf", printf_type);
}

llvm::FunctionCallee CodegenVisitor::get_scanf() {
    auto scanf_ret = builder_.getInt32Ty();
    std::vector<llvm::Type*> scanf_args;
    scanf_args.push_back(builder_.getInt8Ty()->getPointerTo());
    llvm::ArrayRef<llvm::Type*> args_ref(scanf_args);
    auto scanf_type = llvm::FunctionType::get(scanf_ret, args_ref, /* IsVarArg */ true);
    return module_->getOrInsertFunction("scanf", scanf_type);
}

template<class T>
void CodegenVisitor::visit_binary_op(T* binary_op, BinaryOp op_func) {
    auto visit_expr = [this](Expression* expr) -> llvm::Value* {
        expr->accept_visitor(this);
        auto value = latest_values_.top();
        latest_values_.pop();
        return value;
    };

    auto left_value = visit_expr(binary_op->left_expression());
    auto right_value = visit_expr(binary_op->right_expression());
    auto new_value = op_func(left_value, right_value);
    latest_values_.push(new_value);
}

llvm::BasicBlock* CodegenVisitor::generate_block(const std::string& block_name) {
    auto id = "." + std::to_string(blocks_.size());
    auto new_bb = llvm::BasicBlock::Create(context_, block_name + id, current_function_);
    blocks_.push_back(new_bb);
    return new_bb;
}

}; // namespace nezoku
