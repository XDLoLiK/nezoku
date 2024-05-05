#include "mul_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

MulExpression::MulExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

MulExpression::~MulExpression() {
    delete left_;
    delete right_;
}

void MulExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto MulExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto MulExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
