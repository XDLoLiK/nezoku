#ifndef SUB_EXPRESSION_HPP
#define SUB_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class SubExpression: public Expression {
public:
    SubExpression(Expression* left, Expression* right);
    ~SubExpression() final;

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

#endif // SUB_EXPRESSION_HPP
