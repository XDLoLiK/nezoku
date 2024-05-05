#include "and_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

AndExpression::AndExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

AndExpression::~AndExpression() {
    delete left_;
    delete right_;
}

void AndExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto AndExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto AndExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
