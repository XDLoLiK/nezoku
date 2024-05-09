#ifndef BREAK_STATEMENT_HPP
#define BREAK_STATEMENT_HPP

#include "common.hpp"
#include "statement.hpp"

namespace nezoku {

class BreakStatement: public Statement {
public:
    virtual ~BreakStatement() = default;

    void accept_visitor(Visitor* visitor) override;
};

}; // namespace nezoku

#endif // BREAK_STATEMENT_HPP
