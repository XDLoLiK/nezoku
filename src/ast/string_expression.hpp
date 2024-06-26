#ifndef STRING_EXPRESSION_HPP
#define STRING_EXPRESSION_HPP

#include <string>

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class StringExpression: public Expression {
public:
    StringExpression(std::string str);
    virtual ~StringExpression() = default;

    void accept_visitor(Visitor* visitor) override;

    [[nodiscard]]
    auto string() const noexcept -> const std::string&;

private:
    std::string string_;
};

}; // namespace nezoku

#endif // STRING_EXPRESSION_HPP
