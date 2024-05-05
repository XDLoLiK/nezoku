#ifndef ADD_EXPRESSION_HPP
#define ADD_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class AddExpression: public Expression {
public:
    AddExpression(Expression* left, Expression* right);
    ~AddExpression();

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

#endif // ADD_EXPRESSION_HPP
