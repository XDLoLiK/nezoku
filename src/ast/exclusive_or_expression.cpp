#include "exclusive_or_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

XorExpression::XorExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

XorExpression::~XorExpression() {
    delete left_;
    delete right_;
}

void XorExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto XorExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto XorExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
