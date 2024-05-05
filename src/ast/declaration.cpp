#include "declaration.hpp"
#include "expression.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

Declaration::Declaration(TypeSpecifier type, std::string id, Expression* init)
    : variable_type_(type)
    , variable_name_(id)
    , initializer_(init) {}

Declaration::~Declaration() {
    delete initializer_;
}

void Declaration::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto Declaration::variable_type() const noexcept -> TypeSpecifier {
    return variable_type_;
}

[[nodiscard]]
auto Declaration::variable_name() const noexcept -> const std::string& {
    return variable_name_;
}

[[nodiscard]]
auto Declaration::initializer() const noexcept -> Expression* {
    return initializer_;
}

}; // namespace nezoku
