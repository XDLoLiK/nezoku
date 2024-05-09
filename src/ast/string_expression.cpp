#include "string_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

StringExpression::StringExpression(std::string str)
    : string_(str) {}

void StringExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto StringExpression::string() const noexcept -> const std::string& {
    return string_;
};

}; // namespace nezoku
