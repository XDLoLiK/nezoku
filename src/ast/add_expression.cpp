#include "add_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

AddExpression::AddExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

AddExpression::~AddExpression() {
    delete left_;
    delete right_;
}

void AddExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto AddExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto AddExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
