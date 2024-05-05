#ifndef AND_EXPRESSION_HPP
#define AND_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class AndExpression: public Expression {
public:
    AndExpression(Expression* left, Expression* right);
    ~AndExpression() final;

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

#endif // AND_EXPRESSION_HPP
