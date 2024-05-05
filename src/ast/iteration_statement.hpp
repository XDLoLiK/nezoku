#ifndef ITERATION_STATEMENT_HPP
#define ITERATION_STATEMENT_HPP

#include "common.hpp"
#include "statement.hpp"

namespace nezoku {

class IterationStatement: public Statement {
public:
    ~IterationStatement() final;

    void accept_visitor(Visitor* visitor) final;

    void add_condition(Expression* condition);
    void add_statement(Statement* statement);

    [[nodiscard]]
    auto condition() const noexcept -> Expression*;
    [[nodiscard]]
    auto body() const noexcept -> Statement*;

private:
    Expression* condition_;
    Statement* body_;
};

}; // namespace nezoku

#endif // ITERATION_STATEMENT_HPP
