#include <exception>

#include "interpreting_visitor.hpp"
#include "ast/translation_unit.hpp"
#include "ast/function_definition.hpp"
#include "ast/declaration.hpp"
#include "all_statements.hpp"
#include "all_expressions.hpp"

namespace nezoku {

template<class... Ts> struct VariantVisitor: Ts... { using Ts::operator()...; };
template<class... Ts> VariantVisitor(Ts...) -> VariantVisitor<Ts...>;

class BreakException: public std::exception {
public:
    const char* what() const throw() {
        return "Break";
    }
};

class ContinueException: public std::exception {
public:
    const char* what() const throw() {
        return "Continue";
    }
};

class ReturnException: public std::exception {
public:
    const char* what() const throw() {
        return "Return";
    }
};

InterpretingVisitor::InterpretingVisitor(const std::string& file_name)
    : file_name_(file_name) {}

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
    auto name = function_definition->function_name();
    functions_.insert(std::make_pair(name, function_definition));
}

void InterpretingVisitor::visit(Declaration* declaration) {
    auto init_expr = declaration->initializer();
    // TODO: Support more types
    auto init_val = std::make_pair(TypeSpecifier::I32Type, std::any(0));

    if (init_expr) {
        init_expr->accept_visitor(this);
        init_val = latest_values_.top();
        latest_values_.pop();
    }

    auto name = declaration->variable_name();
    current_scope_->add_value(name, init_val);
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
    auto ret_expr = return_statement->expression();

    if (ret_expr) {
        ret_expr->accept_visitor(this);
    }

    throw ReturnException();
}

void InterpretingVisitor::visit([[maybe_unused]] ContinueStatement* continue_statement) {
    throw ContinueException();
}

void InterpretingVisitor::visit([[maybe_unused]] BreakStatement* break_statement) {
    throw BreakException();
}

void InterpretingVisitor::visit(SelectionStatement* selection_statement) {
    auto condition = selection_statement->if_expression();
    condition->accept_visitor(this);
    auto condition_value = latest_values_.top();
    latest_values_.pop();

    // TODO: Support more types.
    auto is_true = std::any_cast<int>(condition_value);
    auto if_body = selection_statement->then_statement();
    auto else_body = selection_statement->else_statement();

    if (is_true) {
        if_body->accept_visitor(this);
    } else if (else_body) {
        else_body->accept_visitor(this);
    }
}

void InterpretingVisitor::visit(IterationStatement* iteration_statement) {
    auto check_condition = [this, iteration_statement]() -> int {
        auto condition = iteration_statement->condition();
        condition->accept_visitor(this);
        auto condition_value = latest_values_.top();
        latest_values_.pop();
        return std::any_cast<int>(condition_value);
    };

    while (check_condition()) {
        try {
            auto body = iteration_statement->body();
            body->accept_visitor(this);
        } catch (const BreakException& break_e) {
            break;
        } catch (const ContinueException& continue_e) {
            continue;
        }
    }
}

void InterpretingVisitor::visit(AssignmentExpression* assignment_expression) {
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

    auto variable = variable_opt.value();
    // TODO: Support more types.
    assert(variable.first == TypeSpecifier::I32Type);

    auto right_expr = assignment_expression->right_expression();
    right_expr->accept_visitor(this);
    auto new_val = latest_values_.top();
    latest_values_.pop();
    // TODO: Support different assignment operations.
    current_scope_->add_value(name, new_val);
    latest_values_.push(new_val);
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
    // TODO: Support function pointers.
    auto left_expr = function_call_expression->function();
    auto id_expr = dynamic_cast<IdentifierExpression*>(left_expr);

    // Type checking for a function name.
    if (!id_expr) {
        // TODO: Throw error.
        return;
    }

    std::vector<Value> args;
    auto arg_list = function_call_expression->argument_list();

    for (const auto& arg : arg_list) {
        arg->accept_visitor(this);
        auto arg_val = latest_values_.top();
        args.push_back(arg_val);
        latest_values_.pop();
    }

    auto name = id_expr->identifier();
    auto found_func = functions_.find(name);

    if (found_func == functions_.end()) {
        // TODO: Handle this case
        return;
    }

    // Create a new scope for each function.
    current_scope_ = std::make_shared<Scope<Value>>(name, current_scope_);
    auto prototype_args = found_func->second->parameter_list();

    for (size_t i = 0; i < prototype_args.size(); i++) {
        auto arg_name = prototype_args[i].second;
        auto arg_val = args.at(i);
        current_scope_->add_value(arg_name, arg_val);
    }

    try {
        auto body = found_func->second->function_body();
        body->accept_visitor(this);
    } catch (const ReturnException& ret_e) {
        // Return value is already at the top of the stack.
    }

    // Return to the parent scope.
    current_scope_ = current_scope_->parent();
}

void InterpretingVisitor::visit(IdentifierExpression* identifier_expression) {
    auto name = identifier_expression->identifier();
    auto variable_opt = scope_find_value(name, current_scope_);
    assert(variable_opt);
    auto variable = variable_opt.value();
    // TODO: Support more types.
    auto value = std::any_cast<int>(variable.second);
    latest_values_.push(std::make_pair(TypeSpecifier::I32Type, std::any(value)));
}

void InterpretingVisitor::visit(ConstantExpression* constant_expression) {
    auto constant = constant_expression->constant();
    auto converted = std::stoll(constant);
    // TODO: Support more types.
    latest_values_.push(std::make_pair(TypeSpecifier::I32Type, std::any(converted)));
}

void InterpretingVisitor::visit(StringExpression* string_expression) {
    // TODO: Support pointers and composite types.
    auto str = string_expression->string();
    auto new_val = std::make_pair(TypeSpecifier::CharType, std::any(str));
    latest_values_.push(new_val);
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
