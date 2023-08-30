// License: The Unlicense (https://unlicense.org)
// vim:et:ts=2:sw=2
#include "argc++/Application.hpp"

#include "argc++/Argument.hpp"

#include <fmt/core.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <span>
#include <string>
#include <utility>

namespace tybl::argcpp {

application::application(std::string p_name, std::string p_version)
  : m_name(std::move(p_name))
  , m_version(std::move(p_version))
  , m_description()
  , m_epilog()
  , m_arguments()
  , m_argument_map() {
  add_argument("-h", "--help").help("Print this message and exit").action([this]() { throw_help_message(); });
  add_argument("--version").help("Print version information and exit").action([this]() { throw_version_message(); });
}

auto application::run(int p_argc, char const** p_argv) -> int {
  parse_arguments(std::span(p_argv, static_cast<size_t>(p_argc)));
  // TODO(tybl):
  // 1. Parse arguments
  // 2. Invoke commands
  return 0;
}

void application::parse_arguments(std::span<char const*> const& p_args) {
  using namespace std::ranges;
  for (auto const& arg : p_args) {
    auto const& arg_it = m_argument_map.find(arg);
    if (arg_it != m_argument_map.end() && arg_it->second->m_action) {
      arg_it->second->m_action();
    }
  }
  // TODO(tybl):
  // 1. Ignore first argument, as it is the name that invoked the program
  // 2. For each of the argument_strings in p_args,
  //  a. Check if the argument_string is a positional argument
  //  b. Check if the argument_string is a defined parameter
  //  c. Check if the argument_string consists of multiple defined parameters
  //     in a compound argument
  //  d. Print an error and usage.
}

// For printing usage
auto application::longest_argument_length() const -> size_t {
  return std::accumulate(m_argument_map.cbegin(), m_argument_map.cend(), 0ULL,
                         [](size_t p_max_length, auto const& p_argument_entry) {
                           return std::max(p_max_length, p_argument_entry.second->length());
                         });
}

void application::throw_help_message() const {
  auto msg = fmt::format("Usage: {} [options]\n\nOptional arguments:\n", m_name);
  for (auto const& arg : m_arguments) {
    for (auto const& name : arg.m_names) {
      msg += fmt::format("{}, ", name);
    }
    msg += fmt::format("{}\n", arg.help());
  }
  throw std::runtime_error(msg);
}

void application::throw_version_message() const {
  throw std::runtime_error(fmt::format("{} version {}", m_name, m_version));
}

void application::index_argument(list_iterator p_argument_iterator) {
  for (auto const& name : p_argument_iterator->m_names) {
    m_argument_map.insert_or_assign(name, p_argument_iterator);
  }
}

} // namespace tybl::argcpp
