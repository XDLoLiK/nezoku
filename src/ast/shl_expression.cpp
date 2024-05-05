#include "shl_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

ShlExpression::ShlExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

ShlExpression::~ShlExpression() {
    delete left_;
    delete right_;
}

void ShlExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto ShlExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto ShlExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
