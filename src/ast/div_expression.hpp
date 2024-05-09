#ifndef DIV_EXPRESSION_HPP
#define DIV_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class DivExpression: public Expression {
public:
    DivExpression(Expression* left, Expression* right);
    ~DivExpression() override;

    void accept_visitor(Visitor* visitor) override;

    [[nodiscard]]
    auto left_expression() const noexcept -> Expression*;
    [[nodiscard]]
    auto right_expression() const noexcept -> Expression*;

private:
    Expression* left_;
    Expression* right_;
};

}; // namespace nezoku

#endif // DIV_EXPRESSION_HPP
