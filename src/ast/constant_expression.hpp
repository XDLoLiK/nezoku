#ifndef CONSTANT_EXPRESSION_HPP
#define CONSTANT_EXPRESSION_HPP

#include <string>

#include "common.hpp"
#include "expression.hpp"

namespace nezoku {

class ConstantExpression: public Expression {
public:
    ConstantExpression(std::string constant);
    ~ConstantExpression();

    void accept_visitor(Visitor* visitor);

    [[nodiscard]]
    auto constant() const noexcept -> const std::string&;

private:
    std::string constant_;
};

}; // namespace nezoku

#endif // CONSTANT_EXPRESSION_HPP
