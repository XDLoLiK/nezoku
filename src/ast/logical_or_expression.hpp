#ifndef LOGICAL_OR_EXPRESSION_HPP
#define LOGICAL_OR_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class LorExpression: public Expression {
public:
    LorExpression(Expression* left, Expression* right);
    ~LorExpression() final;

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

#endif // LOGICAL_OR_EXPRESSION_HPP
