// License: The Unlicense (https://unlicense.org)
// vim:et:ts=2:sw=2
#pragma once

#include "Argument.hpp"

#include <list>
#include <map>
#include <span>
#include <string>
#include <string_view>

namespace tybl::argcpp {

struct Application {

  Application(std::string p_name, std::string p_version);

  // Ref: https://www.modernescpp.com/index.php/c-core-guidelines-rules-for-variadic-templates
  template <typename... Args>
  auto add_argument(Args&&... p_args) -> argument&;

  auto run(int p_argc, char const** p_argv) -> int;

private:
  // Type definitions
  using list_iterator = std::list<argument>::iterator;

  // Private methods
  void parse_arguments(std::span<char const*> const& /*p_args*/);

  // For printing usage
  [[nodiscard]] auto longest_argument_length() const -> size_t;

  void throw_help_message() const;

  void throw_version_message() const;

  void index_argument(list_iterator p_argument_iterator);

  // Member variables
  std::string m_name;        // For printing usage
  std::string m_version;     // For printing usage
  std::string m_description; // For printing usage
  std::string m_epilog;      // For printing usage

  // std::list prevents iterators from being invalidated
  std::list<argument> m_arguments;

  // TODO(tybl): Investigate performance characteristics compared to std::unordered_map
  std::map<std::string_view, list_iterator> m_argument_map;

}; // class Application

// Ref: https://www.modernescpp.com/index.php/c-core-guidelines-rules-for-variadic-templates
template <typename... Args>
auto Application::add_argument(Args&&... p_args) -> argument& {
  auto arg_it = m_arguments.emplace(std::cend(m_arguments), std::forward<Args>(p_args)...);
  index_argument(arg_it);
  return *arg_it;
}

} // namespace tybl::argcpp
