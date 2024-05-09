#ifndef LOGICAL_AND_EXPRESSION_HPP
#define LOGICAL_AND_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class LandExpression: public Expression {
public:
    LandExpression(Expression* left, Expression* right);
    ~LandExpression() override;

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

#endif // LOGICAL_AND_EXPRESSION_HPP
