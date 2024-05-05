#ifndef RETURN_STATEMENT_HPP
#define RETURN_STATEMENT_HPP

#include "common.hpp"
#include "statement.hpp"

namespace nezoku {

class ReturnStatement: public Statement {
public:
    ReturnStatement(Expression* expression = nullptr);
    ~ReturnStatement();

    void accept_visitor(Visitor* visitor);

    [[nodiscard]]
    auto expression() const noexcept -> Expression*;

private:
    Expression* expression_;
};

}; // namespace nezoku

#endif // RETURN_STATEMENT_HPP
