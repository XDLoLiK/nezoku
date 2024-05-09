#ifndef CONTINUE_STATEMENT_HPP
#define CONTINUE_STATEMENT_HPP

#include "common.hpp"
#include "statement.hpp"

namespace nezoku {

class ContinueStatement: public Statement {
public:
    virtual ~ContinueStatement() = default;

    void accept_visitor(Visitor* visitor) override;
};

}; // namespace nezoku

#endif // CONTINUE_STATEMENT_HPP
