#ifndef NEQ_EXPRESSION_HPP
#define NEQ_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class NeqExpression: public Expression {
public:
    NeqExpression(Expression* left, Expression* right);
    ~NeqExpression() override;

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

#endif // NEQ_EXPRESSION_HPP
