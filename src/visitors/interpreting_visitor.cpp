#include "interpreting_visitor.hpp"
#include "ast/translation_unit.hpp"
#include "ast/function_definition.hpp"
#include "ast/declaration.hpp"
#include "all_statements.hpp"
#include "all_expressions.hpp"

namespace nezoku {

template<class... Ts> struct VariantVisitor: Ts... { using Ts::operator()...; };
template<class... Ts> VariantVisitor(Ts...) -> VariantVisitor<Ts...>;

InterpretingVisitor::InterpretingVisitor(std::ostream& stream)
    : stream_(stream) {}

void InterpretingVisitor::visit(TranslationUnit* translation_unit) {
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
void InterpretingVisitor::visit(FunctionDefinition* function_definition) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(Declaration* declaration) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(CompoundStatement* compound_statement) {
    // Create a new scope for each compound statement.
    current_scope_ = std::make_shared<Scope<Value>>(current_scope_);

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

void InterpretingVisitor::visit(ExpressionStatement* expression_statement) {
    auto expression = expression_statement->expression();

    if (expression) {
        expression->accept_visitor(this);
    }
}

void InterpretingVisitor::visit(ReturnStatement* return_statement) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(ContinueStatement* continue_statement) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(BreakStatement* break_statement) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(SelectionStatement* selection_statement) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(IterationStatement* iteration_statement) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(AssignmentExpression* assignment_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(LorExpression* logical_or_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval || rval));
    };
    visit_binary_op(logical_or_expression, call);
}

void InterpretingVisitor::visit(LandExpression* logical_and_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval && rval));
    };
    visit_binary_op(logical_and_expression, call);
}

void InterpretingVisitor::visit(OrExpression* inclusive_or_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval | rval));
    };
    visit_binary_op(inclusive_or_expression, call);
}

void InterpretingVisitor::visit(XorExpression* exclusive_or_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval ^ rval));
    };
    visit_binary_op(exclusive_or_expression, call);
}

void InterpretingVisitor::visit(AndExpression* and_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval & rval));
    };
    visit_binary_op(and_expression, call);
}

void InterpretingVisitor::visit(EqExpression* eq_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval == rval));
    };
    visit_binary_op(eq_expression, call);
}

void InterpretingVisitor::visit(NeqExpression* neq_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval != rval));
    };
    visit_binary_op(neq_expression, call);
}

void InterpretingVisitor::visit(LessExpression* less_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval < rval));
    };
    visit_binary_op(less_expression, call);
}

void InterpretingVisitor::visit(GreaterExpression* greater_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval > rval));
    };
    visit_binary_op(greater_expression, call);
}

void InterpretingVisitor::visit(LeqExpression* leq_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval <= rval));
    };
    visit_binary_op(leq_expression, call);
}

void InterpretingVisitor::visit(GeqExpression* geq_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval >= rval));
    };
    visit_binary_op(geq_expression, call);
}

void InterpretingVisitor::visit(ShlExpression* shl_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval << rval));
    };
    visit_binary_op(shl_expression, call);
}

void InterpretingVisitor::visit(ShrExpression* shr_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval >> rval));
    };
    visit_binary_op(shr_expression, call);
}

void InterpretingVisitor::visit(AddExpression* add_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval + rval));
    };
    visit_binary_op(add_expression, call);
}

void InterpretingVisitor::visit(SubExpression* sub_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval - rval));
    };
    visit_binary_op(sub_expression, call);
}

void InterpretingVisitor::visit(MulExpression* mul_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval * rval));
    };
    visit_binary_op(mul_expression, call);
}

void InterpretingVisitor::visit(DivExpression* div_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval / rval));
    };
    visit_binary_op(div_expression, call);
}

void InterpretingVisitor::visit(ModExpression* mod_expression) {
    auto call = [](Value lhs, Value rhs) -> Value {
        // TODO: Support more types.
        auto lval = std::any_cast<int>(lhs.second);
        auto rval = std::any_cast<int>(rhs.second);
        return std::make_pair(TypeSpecifier::I32Type, std::any(lval % rval));
    };
    visit_binary_op(mod_expression, call);
}


void InterpretingVisitor::visit(FunctionCallExpression* function_call_expression) {
    // TODO: Implement.
}

void InterpretingVisitor::visit(IdentifierExpression* identifier_expression) {
    // TODO: Implement.
}

void InterpretingVisitor::visit(ConstantExpression* constant_expression) {
    // TODO: Implement.
}

void InterpretingVisitor::visit(StringExpression* string_expression) {
    // TODO: Implement.
}

template<class T>
void InterpretingVisitor::visit_binary_op(T* binary_op, BinaryOp op_func) {
    auto visit_expr = [this](Expression* expr) -> Value {
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

}; // namespace nezoku
