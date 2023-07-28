// License: The Unlicense (https://unlicense.org)
#include "argc++/Argument.hpp"

namespace parm {

// For printing usage
auto argument::help(std::string_view p_help) -> argument& {
  m_help = p_help;
  return *this;
}

[[nodiscard]] auto argument::length() const -> size_t {
  return std::accumulate(std::begin(m_names), std::end(m_names), size_t(0), [](const auto& p_sum, const auto& p_string) {
    return p_sum + p_string.size() + 1; // +1 for space between names
  });
}

} // namespace parm

