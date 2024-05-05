#include "iteration_statement.hpp"
#include "expression.hpp"
#include "statement.hpp
#include "visitors/visitor.hpp"

namespace nezoku {

IterationStatement::IterationStatement() {}

IterationStatement::~IterationStatement() {
    delete condition_;
    delete body_;
}

void IterationStatement::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

void IterationStatement::add_condition(Expression* condition) {
    condition_ = condition;
}

void IterationStatement::add_statement(Statement* statement) {
    body_ = statement;
}

[[nodiscard]]
auto IterationStatement::condition() const noexcept -> Expression* {
    return condition_;
};

[[nodiscard]]
auto IterationStatement::body() const noexcept -> Statement* {
    return body_;
};

}; // namespace nezoku
