#include "continue_statement.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

void ContinueStatement::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

}; // namespace nezoku
