#include "leq_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

LeqExpression::LeqExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

LeqExpression::~LeqExpression() {
    delete left_;
    delete right_;
}

void LeqExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto LeqExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto LeqExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
