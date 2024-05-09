#include "constant_expression.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

ConstantExpression::ConstantExpression(std::string constant)
    : constant_(constant) {}

void ConstantExpression::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto ConstantExpression::constant() const noexcept -> const std::string& {
    return constant_;
};

}; // namespace nezoku
