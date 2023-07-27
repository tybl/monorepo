#pragma once
#include <string>

namespace tybl::util {

#ifdef __cpp_lib_string_contains
#warning "Please replace your use of tybl::util::string_contains with std::string::contains"
#endif

template <typename CharType>
auto string_contains(std::basic_string<CharType> const& p_str, CharType p_char) {
   return p_str.find(p_char) != std::string::npos;
}

} // namespace tybl::util
