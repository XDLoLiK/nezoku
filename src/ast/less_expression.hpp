#ifndef LESS_EXPRESSION_HPP
#define LESS_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class LessExpression: public Expression {
public:
    LessExpression(Expression* left, Expression* right);
    ~LessExpression();

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

#endif // LESS_EXPRESSION_HPP
