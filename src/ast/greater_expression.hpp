#ifndef GREATER_EXPRESSION_HPP
#define GREATER_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class GreaterExpression: public Expression {
public:
    GreaterExpression(Expression* left, Expression* right);
    ~GreaterExpression();

    void accept_visitor(Visitor* visitor);

    [[nodiscard]]
    auto left_expression() const noexcept -> Expression*;
    [[nodiscard]]
    auto right_expression() const noexcept -> Expression*;

private:
    Expression* left_;
    Expression* right_;
};

}; // namespace nezoku

#endif // GREATER_EXPRESSION_HPP
