#ifndef FUNCTION_DEFINITION_HPP
#define FUNCTION_DEFINITION_HPP

#include <string>
#include <vector>

#include "common.hpp"
#include "accepter.hpp"
#include "type_specifier.hpp"

namespace nezoku {

class FunctionDefinition: public Accepter {
    using FunctionParameter = std::pair<TypeSpecifier, std::string>;

public:
    FunctionDefinition(TypeSpecifier return_type, std::string id,
                       std::vector<FunctionParameter> parameters, Statement* body);
    ~FunctionDefinition() final;

    void accept_visitor(Visitor* visitor) final;

    [[nodiscard]]
    auto return_type() const noexcept -> TypeSpecifier;
    [[nodiscard]]
    auto function_name() const noexcept -> const std::string&;
    [[nodiscard]]
    auto parameter_list() const noexcept -> const std::vector<FunctionParameter>&;
    [[nodiscard]]
    auto function_body() const noexcept -> Statement*;

private:
    TypeSpecifier return_type_;
    std::string function_name_;
    std::vector<FunctionParameter> parameter_list_;
    Statement* function_body_;
};

}; // namespace nezoku

#endif // FUNCTION_DEFINITION_HPP
