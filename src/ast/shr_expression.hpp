#ifndef SHR_EXPRESSION_HPP
#define SHR_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class ShrExpression: public Expression {
public:
    ShrExpression(Expression* left, Expression* right);
    ~ShrExpression();

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

#endif // SHR_EXPRESSION_HPP
