#include "logical_or_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

LorExpression::LorExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

LorExpression::~LorExpression() {
    delete left_;
    delete right_;
}

void LorExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto LorExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto LorExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
