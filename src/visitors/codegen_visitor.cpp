#include "codegen_visitor.hpp"

#include "ast/translation_unit.hpp"
#include "ast/function_definition.hpp"
#include "ast/declaration.hpp"

#include "ast/statement.hpp"
#include "ast/compound_statement.hpp"
#include "ast/return_statement.hpp"
#include "ast/expression_statement.hpp"
#include "ast/break_statement.hpp"
#include "ast/continue_statement.hpp"
#include "ast/selection_statement.hpp"
#include "ast/iteration_statement.hpp"

#include "ast/expression.hpp"
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

CodegenVisitor::CodegenVisitor(const std::string& file)
    : stream_(file)
    , builder_(context_)
    , module_(std::make_unique<llvm::Module>(file, context_)) {
    // TODO: Implement.
    return;
}

CodegenVisitor::~CodegenVisitor() {
    stream_.close();
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
    // TODO: Implement.
    return;
}

void CodegenVisitor::visit([[maybe_unused]] BreakStatement* break_statement) {
    // TODO: Implement.
    return;
}

void CodegenVisitor::visit(SelectionStatement* selection_statement) {
    // TODO: Implement.
    return;
}

void CodegenVisitor::visit([[maybe_unused]] IterationStatement* iteration_statement) {
    // TODO: Implement.
    return;
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
        return builder_.CreateLogicalOr(lhs, rhs);
    };
    visit_binary_op(eq_expression, call);
}

void CodegenVisitor::visit(NeqExpression* neq_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateLogicalOr(lhs, rhs);
    };
    visit_binary_op(neq_expression, call);
}

void CodegenVisitor::visit(LessExpression* less_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateLogicalOr(lhs, rhs);
    };
    visit_binary_op(less_expression, call);
}

void CodegenVisitor::visit(GreaterExpression* greater_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateLogicalOr(lhs, rhs);
    };
    visit_binary_op(greater_expression, call);
}

void CodegenVisitor::visit(LeqExpression* leq_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateLogicalOr(lhs, rhs);
    };
    visit_binary_op(leq_expression, call);
}

void CodegenVisitor::visit(GeqExpression* geq_expression) {
    auto call = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return builder_.CreateLogicalOr(lhs, rhs);
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
        return builder_.CreateShr(lhs, rhs);
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
        return builder_.CreateMod(lhs, rhs);
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
    // TODO: Implement.
    return;
}

template<class T>
void CodegenVisitor::visit_binary_op(T* binary_op, std::function<llvm::Value* (llvm::Value*, llvm::Value*)> op_func) {
    auto left_expr = binary_op->left_expression();
    left_expr->accept_visitor(this);
    auto left_value = latest_values_.top();
    latest_values_.pop();

    auto right_expr = binary_op->right_expression();
    right_expr->accept_visitor(this);
    auto right_value = latest_values_.top();
    latest_values_.pop();

    auto new_value = op_func(left_value, right_value);
    latest_values_.push(new_value);
}

}; // namespace nezoku
