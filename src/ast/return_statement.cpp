#include "return_statement.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

ReturnStatement::ReturnStatement() {}

ReturnStatement::ReturnStatement(Expression* expression)
    : expression_(expression) {}

ReturnStatement::~ReturnStatement() {
    delete expression_;
}

void ReturnStatement::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto ReturnStatement::expression() const noexcept -> Expression* {
    return expression_;
}

}; // namespace nezoku
