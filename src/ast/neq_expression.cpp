#include "neq_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

NeqExpression::NeqExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

NeqExpression::~NeqExpression() {
    delete left_;
    delete right_;
}

void NeqExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto NeqExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto NeqExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
