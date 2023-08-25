// License: The Unlicense (https://unlicense.org)
// vim:et:ts=2:sw=2
#pragma once

#include <functional>
#include <string>
#include <vector>

namespace tybl::argcpp {

struct argument {
  // Ref: https://stackoverflow.com/questions/13978916/inserting-a-variadic-argument-list-into-a-vector
  template <typename... Args>
  argument(Args... p_arguments)
    : m_names{p_arguments...} {}

  // For printing usage
  auto help(std::string_view p_help) -> argument&;

  auto help() const -> std::string { return m_help; }

  auto action(std::function<void()> p_action) -> argument&;

private:
  // Type definitions
  friend class Application;

  // Private methods
  // For printing usage
  [[nodiscard]] auto length() const -> size_t;

  // Member variables
  std::vector<std::string> m_names;

  std::string m_help;

  std::function<void()> m_action;

}; // class argument

} // namespace tybl::argcpp
