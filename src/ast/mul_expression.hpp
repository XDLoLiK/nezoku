#ifndef MUL_EXPRESSION_HPP
#define MUL_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class MulExpression: public Expression {
public:
    MulExpression(Expression* left, Expression* right);
    ~MulExpression() final;

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

#endif // MUL_EXPRESSION_HPP
