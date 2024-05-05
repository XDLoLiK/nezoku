#ifndef CONTINUE_STATEMENT_HPP
#define CONTINUE_STATEMENT_HPP

#include "common.hpp"
#include "jump_statement.hpp"

namespace nezoku {

class ContinueStatement: public JumpStatement {
public:
    ~ContinueStatement();

    void accept_visitor(Visitor* visitor);
};

}; // namespace nezoku

#endif // CONTINUE_STATEMENT_HPP
