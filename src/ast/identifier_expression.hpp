#ifndef IDENTIFIER_EXPRESSION_HPP
#define IDENTIFIER_EXPRESSION_HPP

#include <string>

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class IdentifierExpression: public Expression {
public:
    IdentifierExpression(std::string identifier);
    virtual ~IdentifierExpression() = default;

    void accept_visitor(Visitor* visitor) override;

    [[nodiscard]]
    auto identifier() const noexcept -> const std::string&;

private:
    std::string identifier_;
};

}; // namespace nezoku

#endif // IDENTIFIER_EXPRESSION_HPP
