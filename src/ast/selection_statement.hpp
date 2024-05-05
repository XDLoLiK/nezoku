#ifndef SELECTION_STATEMENT_HPP
#define SELECTION_STATEMENT_HPP

#include <variant>
#include <vector>

#include "common.hpp"
#include "statement.hpp"

namespace nezoku {

class SelectionStatement: public Statement {
public:
    SelectionStatement(Expression* if_expression, Statement* then_statement, Statement* else_statement = nullptr);
    ~SelectionStatement();

    void accept_visitor(Visitor* visitor);

    [[nodiscard]]
    auto if_expression() const noexcept -> Expression*;
    [[nodiscard]]
    auto then_statement() const noexcept -> Statement*;
    [[nodiscard]]
    auto else_statement() const noexcept -> Statement*;

private:
    Expression* if_expression_;
    Statement* then_statement_;
    Statement* else_statement_;
};

}; // namespace nezoku

#endif // SELECTION_STATEMENT_HPP
