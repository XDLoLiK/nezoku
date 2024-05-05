#ifndef DECLARATION_HPP
#define DECLARATION_HPP

#include <string>
#include <vector>

#include "common.hpp"
#include "accepter.hpp"
#include "type_specifier.hpp"

namespace nezoku {

class Declaration: public Accepter {
public:
    Declaration(TypeSpecifier type, std::string id, Expression* initializer);
    ~Declaration() final;
  
    void accept_visitor(Visitor* visitor) final;

    [[nodiscard]]
    auto variable_type() const noexcept -> TypeSpecifier;
    [[nodiscard]]
    auto variable_name() const noexcept -> const std::string&;
    [[nodiscard]]
    auto initializer() const noexcept -> Expression*;

private:
    TypeSpecifier variable_type_;
    std::string variable_name_;
    Expression* initializer_;

};

}; // namespace nezoku

#endif // DECLARATION_HPP
