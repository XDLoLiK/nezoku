#ifndef ACCEPTER_HPP
#define ACCEPTER_HPP

#include "common.hpp"

namespace nezoku {

class Accepter {
public:
    virtual ~Accepter() = 0;

    virtual void accept_visitor(Visitor* visitor) = 0;
};

}; // namespace nezoku

#endif // ACCEPTER_HPP
