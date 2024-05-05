#ifndef ASSIGNMENT_EXPRESSION_HPP
#define ASSIGNMENT_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"
#include "assignment_operator.hpp"

namespace nezoku {

class AssignmentExpression: public Expression {
public:
    AssignmentExpression(Expression* left, AssignmentOperator op, Expression* right);
    ~AssignmentExpression();

    void accept_visitor(Visitor* visitor);

    [[nodiscard]]
    auto left_expression() const noexcept -> Expression*;
    [[nodiscard]]
    auto op() const noexcept -> AssignmentOperator;
    [[nodiscard]]
    auto right_expression() const noexcept -> Expression*;

private:
    Expression* left_;
    AssignmentOperator operator_;
    Expression* right_;
};

}; // namespace nezoku

#endif // ASSIGNMENT_EXPRESSION_HPP
