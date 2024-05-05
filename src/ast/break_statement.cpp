#include "break_statement.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

BreakStatement::~BreakStatement() {}

void BreakStatement::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

}; // namespace nezoku
