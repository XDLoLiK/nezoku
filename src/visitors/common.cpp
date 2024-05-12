#include "common.hpp"

namespace nezoku {

std::string_view get_constant_suffix(const std::string& constnat) {
    auto suffix_start = constnat.rfind("_");

    if (suffix_start == std::string::npos) {
        return std::string_view();
    } else {
        return std::string_view(constnat).substr(suffix_start + 1);
    }
}

std::string remove_constant_suffix(const std::string& constnat) {
    auto suffix_start = constnat.rfind("_");
    return constnat.substr(0, suffix_start);
}

TypeSpecifier constant_suffix_to_type(const std::string& suffix) {
    if (suffix == "i8") return TypeSpecifier::I8Type;
    if (suffix == "i16") return TypeSpecifier::I16Type;
    if (suffix == "i32") return TypeSpecifier::I32Type;
    if (suffix == "i64") return TypeSpecifier::I64Type;
    if (suffix == "u8") return TypeSpecifier::U8Type;
    if (suffix == "u16") return TypeSpecifier::U16Type;
    if (suffix == "u32") return TypeSpecifier::U32Type;
    if (suffix == "u64") return TypeSpecifier::U64Type;
    if (suffix == "f32") return TypeSpecifier::F32Type;
    if (suffix == "f64") return TypeSpecifier::F64Type;
    if (suffix == "char") return TypeSpecifier::CharType;
    if (suffix == "bool") return TypeSpecifier::BoolType;
    return TypeSpecifier::I32Type;
}

}; // namespace nezoku
