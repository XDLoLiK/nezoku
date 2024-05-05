#ifndef CONTINUE_STATEMENT_HPP
#define CONTINUE_STATEMENT_HPP

#include "common.hpp"
#include "jump_statement.hpp"

namespace nezoku {

class ContinueStatement: public JumpStatement {
public:
    ~ContinueStatement() final;

    void accept_visitor(Visitor* visitor) final;
};

}; // namespace nezoku

#endif // CONTINUE_STATEMENT_HPP
