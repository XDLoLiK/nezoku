#ifndef MOD_EXPRESSION_HPP
#define MOD_EXPRESSION_HPP

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class ModExpression: public Expression {
public:
    ModExpression(Expression* left, Expression* right);
    ~ModExpression() override;

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

#endif // MOD_EXPRESSION_HPP
