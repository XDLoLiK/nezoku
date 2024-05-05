#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include "common.hpp"
#include "accepter.hpp"

namespace nezoku {

class Statement: public Accepter {
public:
    virtual ~Statement() = 0;

    virtual void accept_visitor(Visitor* visitor) = 0;
};

}; // namespace nezoku

#endif // STATEMENT_HPP
