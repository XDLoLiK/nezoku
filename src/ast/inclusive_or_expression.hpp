#ifndef INCLUSIVE_OR_EXPRESSION_HPP
#define INCLUSIVE_OR_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class OrExpression: public Expression {
public:
    OrExpression(Expression* left, Expression* right);
    ~OrExpression();

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

#endif // INCLUSIVE_OR_EXPRESSION_HPP
