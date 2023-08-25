// License: The Unlicense (https://unlicense.org)
#include "cli/Command.hpp"

#include <cassert>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <span>
#include <stdexcept> // std::runtime_error
#include <variant>
#include <vector>

namespace ogre {

auto option::add_help(std::string_view p_help) -> option& {
  m_help = p_help;
  return *this;
}

void option::parse(std::span<std::string_view> p_args, parameters& p_params) {
  if (p_args.empty()) {
    throw std::runtime_error("Error: Unknown option");
  }
  if (!is_invoked_option(p_args.front())) {
    throw std::runtime_error("Error: Invoked command with different name");
  }
  for (auto name : m_names) {
    p_params.options[name] = "true";
  }
}

auto option::names() const -> std::vector<std::string_view> const& {
  return m_names;
}

[[nodiscard]] inline auto option::is_invoked_option(std::string_view p_name) const
    -> bool {
  return m_names.end() != std::find(m_names.begin(), m_names.end(), p_name);
}

command::~command() = default;

auto command::add_help(std::string_view /*p_help*/) -> command& {
  //m_help = p_help;
  return *this;
}

auto command::add_action(callback p_action) -> command& {
  m_action = std::move(p_action);
  return *this;
}

auto command::get_subcommand(std::string_view p_sv) -> command& {
  return *std::get<command_iter>(m_str_to_param_map.at(p_sv));
}

auto command::get_option(std::string_view p_sv) -> option& {
  return *std::get<option_iter>(m_str_to_param_map.at(p_sv));
}

// parse() constructs an Action object containing the callable object
// and the parameters to provide to it. All parameters are provided as
// strings on the command line, so they are provided as strings to the
// callable object.
auto command::run(std::span<std::string_view> p_args) -> int {
  parameters params;
  auto action = parse(p_args, params);
  return action(params);
}

[[nodiscard]] inline auto
command::is_invoked_command(std::string_view p_name) const -> bool {
  return names().end() != std::find(names().begin(), names().end(), p_name);
}

auto command::parse(std::span<std::string_view> p_args, parameters& p_params)
    -> command::callback& {
  if (p_args.empty()) {
    throw std::runtime_error("Error: Unknown command");
  }
  if (!is_invoked_command(p_args.front())) {
    throw std::runtime_error("Error: Command invoked with incorrect name");
  }
  p_args = p_args.subspan(1);
  while (!p_args.empty()) {
    auto sub = m_str_to_param_map.find(p_args.front());
    if (m_str_to_param_map.end() != sub) {
      // The argument is an option or subcommand
      if (std::holds_alternative<command_iter>(sub->second)) {
        return std::get<command_iter>(sub->second)->parse(p_args, p_params);
      }
      // assert(std::holds_alternative<option_iter>(sub->second));
      std::get<option_iter>(sub->second)->parse(p_args, p_params);
    } else {
      p_params.arguments.push_back(p_args.front());
    }
    p_args = p_args.subspan(1);
  }
  return m_action;
}

} // namespace ogre
