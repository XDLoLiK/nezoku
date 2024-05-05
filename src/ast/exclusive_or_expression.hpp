#ifndef EXLCUSIVE_OR_EXPRESSION_HPP
#define EXLCUSIVE_OR_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class XorExpression: public Expression {
public:
    XorExpression(Expression* left, Expression* right);
    ~XorExpression();

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

#endif // EXLCUSIVE_OR_EXPRESSION_HPP
