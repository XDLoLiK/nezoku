#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "common.hpp"
#include "accepter.hpp"

namespace nezoku {

class Expression: public Accepter {
public:
    virtual ~Expression() = default;

    virtual void accept_visitor(Visitor* visitor) = 0;
};

}; // namespace nezoku

#endif // EXPRESSION_HPP
