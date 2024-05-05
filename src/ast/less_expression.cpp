#include "less_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

LessExpression::LessExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

LessExpression::~LessExpression() {
    delete left_;
    delete right_;
}

void LessExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto LessExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto LessExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
