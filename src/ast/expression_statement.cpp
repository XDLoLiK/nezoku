#include "expression_statement.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

ExpressionStatement::ExpressionStatement(Expression* expression)
    : expression_(expression) {}

ExpressionStatement::~ExpressionStatement() {
    delete expression_;
}

void ExpressionStatement::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto ExpressionStatement::expression() const noexcept -> Expression* {
    return expression_;
};

}; // namespace nezoku
