#include "geq_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

GeqExpression::GeqExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

GeqExpression::~GeqExpression() {
    delete left_;
    delete right_;
}

void GeqExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto GeqExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto GeqExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
