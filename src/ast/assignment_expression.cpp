#include "assignment_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

AssignmentExpression::AssignmentExpression(Expression* left, AssignmentOperator op, Expression* right)
    : left_(left)
    , operator_(op)
    , right_(right) {}

AssignmentExpression::~AssignmentExpression() {
    delete left_;
    delete right_;
}

void AssignmentExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto AssignmentExpression::left_expression() const noexcept -> Expression* {
    return left_;
};

[[nodiscard]]
auto AssignmentExpression::op() const noexcept -> AssignmentOperator {
    return operator_;
};

[[nodiscard]]
auto AssignmentExpression::right_expression() const noexcept -> Expression* {
    return right_;
};

}; // namespace nezoku
