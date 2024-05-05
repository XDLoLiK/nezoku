#include "shr_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

ShrExpression::ShrExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

ShrExpression::~ShrExpression() {
    delete left_;
    delete right_;
}

void ShrExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto ShrExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto ShrExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
