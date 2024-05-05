#include "selection_statement.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

SelectionStatement::SelectionStatement(Expression* if_expression, Statement* then_statement, Statement* else_statement)
    : if_expression_(if_expression)
    , then_statement_(then_statement)
    , else_statement_(else_statement) {}

SelectionStatement::~SelectionStatement() {
    delete if_expression_;
    delete then_statement_;
    delete else_statement_;
}

void SelectionStatement::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto SelectionStatement::if_expression() const noexcept -> Expression* {
    return if_expression_;
};

[[nodiscard]]
auto SelectionStatement::then_statement() const noexcept -> Statement* {
    return then_statement_;
};

[[nodiscard]]
auto SelectionStatement::else_statement() const noexcept -> Statement* {
    return else_statement_;
};

}; // namespace nezoku
