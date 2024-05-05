#include "function_definition.hpp"
#include "statement.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

FunctionDefinition::FunctionDefinition(TypeSpecifier return_type, std::string id,
                                       std::vector<FunctionParameter> parameters, Statement* body)
    : return_type_(return_type)
    , function_name_(id)
    , parameter_list_(parameters)
    , function_body_(body) {}

FunctionDefinition::~FunctionDefinition() {
    delete function_body_;
}

void FunctionDefinition::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

[[nodiscard]]
auto FunctionDefinition::return_type() const noexcept -> TypeSpecifier {
    return return_type_;
}

[[nodiscard]]
auto FunctionDefinition::function_name() const noexcept -> const std::string& {
    return function_name_;
}

[[nodiscard]]
auto FunctionDefinition::parameter_list() const noexcept -> const std::vector<FunctionParameter>& {
    return parameter_list_;
}

[[nodiscard]]
auto FunctionDefinition::function_body() const noexcept -> Statement* {
    return function_body_;
}

}; // namespace nezoku
