#ifndef LEQ_EXPRESSION_HPP
#define LEQ_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class LeqExpression: public Expression {
public:
    LeqExpression(Expression* left, Expression* right);
    ~LeqExpression();

    void accept_visitor(Visitor* visitor);

    [[nodiscard]]
    auto left_expression() const noexcept -> Expression*;
    [[nodiscard]]
    auto right_expression() const noexcept -> Expression*;

private:
    Expression* left_;
    Expression* right_;
};

}; // namespace nezoku

#endif // LEQ_EXPRESSION_HPP
