#ifndef NEZOKU_VISITORS_COMMON_HPP
#define NEZOKU_VISITORS_COMMON_HPP

#include <string>

#include "ast/type_specifier.hpp"

namespace nezoku {

std::string_view get_constant_suffix(const std::string& constnat);
std::string remove_constant_suffix(const std::string& constnat);
TypeSpecifier constant_suffix_to_type(const std::string& suffix);

}; // namespace nezoku

#endif // NEZOKU_VISITORS_COMMON_HPP
