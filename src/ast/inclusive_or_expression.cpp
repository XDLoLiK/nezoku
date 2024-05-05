#include "inclusive_or_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

OrExpression::OrExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

OrExpression::~OrExpression() {
    delete left_;
    delete right_;
}

void OrExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto OrExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto OrExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
