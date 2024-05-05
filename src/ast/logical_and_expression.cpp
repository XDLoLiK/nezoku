#include "logical_and_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

LandExpression::LandExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

LandExpression::~LandExpression() {
    delete left_;
    delete right_;
}

void LandExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto LandExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto LandExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
