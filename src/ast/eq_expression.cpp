#include "eq_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

EqExpression::EqExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

EqExpression::~EqExpression() {
    delete left_;
    delete right_;
}

void EqExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto EqExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto EqExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
