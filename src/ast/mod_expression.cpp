#include "mod_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

ModExpression::ModExpression(Expression* left, Expression* right)
    : left_(left)
    , right_(right) {}

ModExpression::~ModExpression() {
    delete left_;
    delete right_;
}

void ModExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto ModExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto ModExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
