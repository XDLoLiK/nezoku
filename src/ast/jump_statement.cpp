#include "jump_statement.hpp"
#include "continue_statement.hpp"
#include "break_statement.hpp"
#include "return_statement.hpp"

namespace nezoku {

JumpStatement* JumpStatement::create_continue() {
    return reinterpret_cast<JumpStatement*>(new ContinueStatement());
}

JumpStatement* JumpStatement::create_break() {
    return reinterpret_cast<JumpStatement*>(new BreakStatement());
}

JumpStatement* JumpStatement::create_return() {
    return reinterpret_cast<JumpStatement*>(new ReturnStatement());
}

JumpStatement* JumpStatement::create_return(Expression* expression) {
    return reinterpret_cast<JumpStatement*>(new ReturnStatement(expression));
}

}; // namespace nezoku
