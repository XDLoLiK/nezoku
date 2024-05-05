#ifndef SHL_EXPRESSION_HPP
#define SHL_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class ShlExpression: public Expression {
public:
    ShlExpression(Expression* left, Expression* right);
    ~ShlExpression() final;

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

#endif // SHL_EXPRESSION_HPP
