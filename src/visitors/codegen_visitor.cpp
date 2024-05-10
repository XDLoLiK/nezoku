#include "codegen_visitor.hpp"

#include "ast/translation_unit.hpp"
#include "ast/function_definition.hpp"
#include "ast/declaration.hpp"

#include "ast/compound_statement.hpp"
#include "ast/return_statement.hpp"
#include "ast/expression_statement.hpp"
#include "ast/break_statement.hpp"
#include "ast/continue_statement.hpp"
#include "ast/selection_statement.hpp"
#include "ast/iteration_statement.hpp"

#include "ast/comma_expression.hpp"
#include "ast/assignment_expression.hpp"
#include "ast/logical_or_expression.hpp"
#include "ast/logical_and_expression.hpp"
#include "ast/inclusive_or_expression.hpp"
#include "ast/exclusive_or_expression.hpp"
#include "ast/and_expression.hpp"
#include "ast/eq_expression.hpp"
#include "ast/neq_expression.hpp"
#include "ast/less_expression.hpp"
#include "ast/greater_expression.hpp"
#include "ast/leq_expression.hpp"
#include "ast/geq_expression.hpp"
#include "ast/shl_expression.hpp"
#include "ast/shr_expression.hpp"
#include "ast/add_expression.hpp"
#include "ast/sub_expression.hpp"
#include "ast/mul_expression.hpp"
#include "ast/div_expression.hpp"
#include "ast/mod_expression.hpp"
#include "ast/identifier_expression.hpp"
#include "ast/constant_expression.hpp"
#include "ast/string_expression.hpp"

#include "ast/type_specifier.hpp"
#include "ast/assignment_operator.hpp"

namespace nezoku {

template<class... Ts> struct VariantVisitor: Ts... { using Ts::operator()...; };
template<class... Ts> VariantVisitor(Ts...) -> VariantVisitor<Ts...>;

template<class T>
static T parse_constant(const std::string& constant) {
    // TODO: Implement.
    return;
}

CodegenVisitor::CodegenVisitor(const std::string& mod_name)
    : builder_(context_)
    , module_(std::make_unique<llvm::Module>(mod_name, context_)) {
    // TODO: Implement.
    return;
}

std::error_code CodegenVisitor::write_to(const std::string& file_name) {
    llvm::StringRef file_ref(file_name);
    std::error_code err;
    llvm::raw_fd_ostream out_file(file_ref, err);
    module_->print(out_file, nullptr);
    out_file.flush();
    out_file.close();
    return err;
}

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
}

void CodegenVisitor::visit(Declaration* declaration) {
    // TODO: Implement.
    return;
}

void CodegenVisitor::visit(FunctionDefinition* function_definition) {
    // TODO: Implement.
    return;
}

void CodegenVisitor::visit(CompoundStatement* compound_statement) {
    for (const auto& block_item: compound_statement->block_item_list()) {
        std::visit(
            VariantVisitor{
                [this](Declaration* declaration) { declaration->accept_visitor(this); },
                [this](Statement* statement) { statement->accept_visitor(this); }
            },
            block_item
        );
    }
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
        builder_.CreateBr(cond_block_);
    } else {
        // TODO: Throw error.
    }
}

void CodegenVisitor::visit([[maybe_unused]] BreakStatement* break_statement) {
    if (out_block_) {
        builder_.CreateBr(out_block_);
    } else {
        // TODO: Throw error.
    }
}

void CodegenVisitor::visit(SelectionStatement* selection_statement) {
    auto then_block = generate_block();
    llvm::BasicBlock* else_block = nullptr;
    auto out_block = generate_block();

    auto condition = selection_statement->if_expression();
    condition->accept_visitor(this);
    auto condition_value = latest_values_.top();
    latest_values_.pop();

    auto else_body = selection_statement->else_statement();

    if (else_body) {
        else_block = generate_block();
        builder_.CreateCondBr(condition_value, then_block, else_block);
    } else {
        builder_.CreateCondBr(condition_value, then_block, out_block);
    }

    builder_.SetInsertPoint(then_block);
    auto if_body = selection_statement->then_statement();
    if_body->accept_visitor(this);
    builder_.CreateBr(out_block);

    if (else_body) {
        builder_.SetInsertPoint(else_block);
        else_body->accept_visitor(this);
        builder_.CreateBr(out_block);
    }

    builder_.SetInsertPoint(out_block);
}

void CodegenVisitor::visit([[maybe_unused]] IterationStatement* iteration_statement) {
    cond_block_ = generate_block();
    auto iter_block = generate_block();
    out_block_ = generate_block();

    builder_.SetInsertPoint(cond_block_);
    auto condition = iteration_statement->condition();
    condition->accept_visitor(this);
    auto condition_value = latest_values_.top();
    latest_values_.pop();
    builder_.CreateCondBr(condition_value, iter_block, out_block_);

    builder_.SetInsertPoint(iter_block);
    auto body = iteration_statement->body();
    body->accept_visitor(this);
    builder_.CreateBr(cond_block_);
    
    builder_.SetInsertPoint(out_block_);
    cond_block_ = nullptr;
    out_block_ = nullptr;
}

void CodegenVisitor::visit(AssignmentExpression* assignment_expression) {
    // TODO: Implement.
    return;
}

void CodegenVisitor::visit(LorExpression* logical_or_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateLogicalOr(lhs, rhs);
    };
    visit_binary_op(logical_or_expression, call);
}

void CodegenVisitor::visit(LandExpression* logical_and_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateLogicalAnd(lhs, rhs);
    };
    visit_binary_op(logical_and_expression, call);
}

void CodegenVisitor::visit(OrExpression* inclusive_or_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateOr(lhs, rhs);
    };
    visit_binary_op(inclusive_or_expression, call);
}

void CodegenVisitor::visit(XorExpression* exclusive_or_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateXor(lhs, rhs);
    };
    visit_binary_op(exclusive_or_expression, call);
}

void CodegenVisitor::visit(AndExpression* and_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateAnd(lhs, rhs);
    };
    visit_binary_op(and_expression, call);
}

void CodegenVisitor::visit(EqExpression* eq_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateICmpEQ(lhs, rhs);
    };
    visit_binary_op(eq_expression, call);
}

void CodegenVisitor::visit(NeqExpression* neq_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateICmpNE(lhs, rhs);
    };
    visit_binary_op(neq_expression, call);
}

void CodegenVisitor::visit(LessExpression* less_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateICmpSLT(lhs, rhs);
    };
    visit_binary_op(less_expression, call);
}

void CodegenVisitor::visit(GreaterExpression* greater_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateICmpSGT(lhs, rhs);
    };
    visit_binary_op(greater_expression, call);
}

void CodegenVisitor::visit(LeqExpression* leq_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateICmpSLE(lhs, rhs);
    };
    visit_binary_op(leq_expression, call);
}

void CodegenVisitor::visit(GeqExpression* geq_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateICmpSGE(lhs, rhs);
    };
    visit_binary_op(geq_expression, call);
}

void CodegenVisitor::visit(ShlExpression* shl_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateShl(lhs, rhs);
    };
    visit_binary_op(shl_expression, call);
}

void CodegenVisitor::visit(ShrExpression* shr_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateLShr(lhs, rhs);
    };
    visit_binary_op(shr_expression, call);
}

void CodegenVisitor::visit(AddExpression* add_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateAdd(lhs, rhs);
    };
    visit_binary_op(add_expression, call);
}

void CodegenVisitor::visit(SubExpression* sub_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateSub(lhs, rhs);
    };
    visit_binary_op(sub_expression, call);
}

void CodegenVisitor::visit(MulExpression* mul_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateMul(lhs, rhs);
    };
    visit_binary_op(mul_expression, call);
}

void CodegenVisitor::visit(DivExpression* div_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateSDiv(lhs, rhs);
    };
    visit_binary_op(div_expression, call);
}

void CodegenVisitor::visit(ModExpression* mod_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateSRem(lhs, rhs);
    };
    visit_binary_op(mod_expression, call);
}

void CodegenVisitor::visit(IdentifierExpression* identifier_expression) {
    // TODO: Implement.
    return;
}

void CodegenVisitor::visit(ConstantExpression* constant_expression) {
    // TODO: Implement.
    return;
}

void CodegenVisitor::visit(StringExpression* string_expression) {
    auto value = builder_.CreateGlobalStringPtr(string_expression->string());
    latest_values_.push(value);
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

llvm::BasicBlock* CodegenVisitor::generate_block() {
    auto id = std::to_string(blocks_++);
    return llvm::BasicBlock::Create(context_, "Block" + id, current_function_);
}

}; // namespace nezoku
