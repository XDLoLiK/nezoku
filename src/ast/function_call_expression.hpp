#ifndef FUNCTION_CALL_EXPRESSION_HPP
#define FUNCTION_CALL_EXPRESSION_HPP

#include <vector>

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class FunctionCallExpression: public Expression {
public:
    FunctionCallExpression(Expression* function, std::vector<Expression*> argument_list = std::vector<Expression*>());
    ~FunctionCallExpression() override;

    void accept_visitor(Visitor* visitor) override;

    [[nodiscard]]
    auto function() const noexcept -> Expression*;
    [[nodiscard]]
    auto argument_list() const noexcept -> const std::vector<Expression*>&;

private:
    Expression* function_;
    std::vector<Expression*> argument_list_;
};

}; // namespace nezoku

#endif // FUNCTION_CALL_EXPRESSION_HPP
