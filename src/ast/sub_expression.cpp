#include "sub_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

SubExpression::SubExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

SubExpression::~SubExpression() {
    delete left_;
    delete right_;
}

void SubExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto SubExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto SubExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
