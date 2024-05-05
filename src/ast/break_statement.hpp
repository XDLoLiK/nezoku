#ifndef BREAK_STATEMENT_HPP
#define BREAK_STATEMENT_HPP

#include "common.hpp"
#include "jump_statement.hpp"

namespace nezoku {

class BreakStatement: public JumpStatement {
public:
    ~BreakStatement() final;

    void accept_visitor(Visitor* visitor) final;
};

}; // namespace nezoku

#endif // BREAK_STATEMENT_HPP
