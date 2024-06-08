#ifndef TYPE_SPECIFIER_HPP
#define TYPE_SPECIFIER_HPP

#include "common.hpp"

namespace nezoku {

enum class TypeSpecifier {
    UnitType = 0,
    I8Type = 1,
    I16Type = 2,
    I32Type = 3,
    I64Type = 4,
    U8Type = 5,
    U16Type = 6,
    U32Type = 7,
    U64Type = 8,
    BoolType = 9,
    CharType = 10,
    F32Type = 11,
    F64Type = 12,
    MaxType = 13,
};

}; // namespace nezoku

#endif // TYPE_SPECIFIER_HPP
