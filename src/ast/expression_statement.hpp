#ifndef EXPRESSION_STATEMENT_HPP
#define EXPRESSION_STATEMENT_HPP

#include "common.hpp"
#include "statement.hpp"

namespace nezoku {

class ExpressionStatement: public Statement {
public:
    ExpressionStatement(Expression* expression = nullptr);
    ~ExpressionStatement() override;

    void accept_visitor(Visitor* visitor) override;

    [[nodiscard]]
    auto expression() const noexcept -> Expression*;

private:
    Expression* expression_;
};

}; // namespace nezoku

#endif // EXPRESSION_STATEMENT_HPP
