#ifndef JUMP_STATEMENT_HPP
#define JUMP_STATEMENT_HPP

#include "common.hpp"
#include "statement.hpp"

namespace nezoku {

class JumpStatement: public Statement {
public:
    ~JumpStatement() = 0;

    void accept_visitor(Visitor* visitor) = 0;

    static JumpStatement* create_continue();
    static JumpStatement* create_break();
    static JumpStatement* create_return();
    static JumpStatement* create_return(Expression* expression);
};

}; // namespace nezoku

#endif // JUMP_STATEMENT_HPP
