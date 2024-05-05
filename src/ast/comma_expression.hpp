#ifndef COMMA_EXPRESSION_HPP
#define COMMA_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class CommaExpression: public Expression {
public:
    CommaExpression(Expression* left, Expression* right);
    ~CommaExpression() final;

    void accept_visitor(Visitor* visitor) final;

    [[nodiscard]]
    auto left_expression() const noexcept -> Expression*;
    [[nodiscard]]
    auto right_expression() const noexcept -> Expression*;

private:
    Expression* left_;
    Expression* right_;
};

}; // namespace nezoku

#endif // COMMA_EXPRESSION_HPP
