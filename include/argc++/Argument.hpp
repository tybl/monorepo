// License: The Unlicense (https://unlicense.org)
#pragma once

#include <string>
#include <vector>

namespace tybl::argcpp {

class argument {
  friend class Application;

  std::vector<std::string> m_names;

  std::string m_help;

public:
  // Ref: https://stackoverflow.com/questions/13978916/inserting-a-variadic-argument-list-into-a-vector
  template <typename... Args>
  argument(Args... p_arguments)
    : m_names{p_arguments...} {}

  // For printing usage
  auto help(std::string_view p_help) -> argument&;

private:
  // For printing usage
  [[nodiscard]] auto length() const -> size_t;

}; // class argument

} // namespace tybl::argcpp
