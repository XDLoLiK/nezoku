#include "comma_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

CommaExpression::CommaExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

CommaExpression::~CommaExpression() {
    delete left_;
    delete right_;
}

void CommaExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto CommaExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto CommaExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
