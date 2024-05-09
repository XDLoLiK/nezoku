#ifndef EQ_EXPRESSION_HPP
#define EQ_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class EqExpression: public Expression {
public:
    EqExpression(Expression* left, Expression* right);
    ~EqExpression() override;

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

#endif // EQ_EXPRESSION_HPP
