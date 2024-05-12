#include "function_call_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

FunctionCallExpression::FunctionCallExpression(Expression* function, std::vector<Expression*> argument_list)
    : function_(function)
    , argument_list_(argument_list) {}

FunctionCallExpression::~FunctionCallExpression() {
    delete function_;
    
    for (auto expr : argument_list_) {
        delete expr;
    }
}

void FunctionCallExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto FunctionCallExpression::function() const noexcept -> Expression* {
    return function_;
};

[[nodiscard]]
auto FunctionCallExpression::argument_list() const noexcept -> const std::vector<Expression*>& {
    return argument_list_;
};

}; // namespace nezoku
