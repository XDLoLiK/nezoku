#ifndef ASSIGNMENT_OPERATOR_HPP
#define ASSIGNMENT_OPERATOR_HPP

#include "common.hpp"

namespace nezoku {

enum class AssignmentOperator {
    NoAssign = 0,
    Assign = 1,
    AddAssign = 2,
    SubAssign = 3,
    MulAssign = 4,
    DivAssign = 5,
    ModAssign = 6,
    AndAssign = 7,
    OrAssign = 8,
    XorAssign = 9,
    ShlAssign = 10,
    ShrAssign = 11,
    MaxAssign = 12,
};

}; // namespace nezoku

#endif // ASSIGNMENT_OPERATOR_HPP
