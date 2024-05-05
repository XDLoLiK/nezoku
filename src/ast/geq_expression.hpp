#ifndef GEQ_EXPRESSION_HPP
#define GEQ_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class GeqExpression: public Expression {
public:
    GeqExpression(Expression* left, Expression* right);
    ~GeqExpression() final;

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

#endif // GEQ_EXPRESSION_HPP
