#include "identifier_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

IdentifierExpression::IdentifierExpression(std::string identifier)
    : identifier_(identifier) {}

IdentifierExpression::~IdentifierExpression() {}

void IdentifierExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto IdentifierExpression::identifier() const noexcept -> const std::string& {
    return identifier_;
};

}; // namespace nezoku
