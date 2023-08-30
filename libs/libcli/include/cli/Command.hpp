// License: The Unlicense (https://unlicense.org)
#pragma once

#include <functional> // std::function
#include <map>        // std::map
#include <span>       // std::span
#include <string_view>
#include <vector> // std::vector

#include <iostream>
#include <list>
// #include <stdexcept>
#include <variant>

namespace ogre {

struct parameters {
  parameters();
  std::map<std::string_view, std::string_view> options;
  std::vector<std::string_view> arguments;
}; // struct Parameters

class option {

  // - mNames: All the names that can be used to supply a parameter
  std::vector<std::string_view> m_names;

  // - mHelp: A description of the parameter
  std::string_view m_help;

public:
  template <typename... Args>
  option(Args... p_names)
    : m_names{p_names...}
    , m_help() {}

  virtual ~option() = default;

  virtual auto add_help(std::string_view p_help) -> option&;

  void parse(std::span<std::string_view> p_args, parameters& p_params);

  [[gnu::const]] auto names() const -> std::vector<std::string_view> const&;

  [[nodiscard]] inline auto is_invoked_option(std::string_view p_name) const -> bool;

}; // class Option

// A command can have multiple names
// A command can have help text
class command : public option {
  using command_iter = std::list<command>::iterator;
  using option_iter = std::list<option>::iterator;
  using param_iter = std::variant<command_iter, option_iter>;
  using callback = std::function<int(parameters const&)>;

  // Members used to specify a command:

  // - mNames: All the names that can be used to invoke the command
  // std::vector<std::string_view> mNames;

  // - mHelp: A description of how to use the command
  std::string_view m_help;

  callback m_action;

  std::list<command> m_subcommands;
  std::list<option> m_options;
  std::map<std::string_view, param_iter> m_str_to_param_map;

public:
  template <typename... Args>
  command(Args... p_names)
    : option{p_names...}
    , m_help()
    , m_action()
    , m_subcommands()
    , m_options()
    , m_str_to_param_map() {}

  virtual ~command();

  virtual auto add_help(std::string_view p_help) -> command&;

  template <typename... Args>
  auto add_subcommand(Args&&... p_names) -> command& {
    auto new_subcommand = m_subcommands.emplace(m_subcommands.cend(), std::forward<Args>(p_names)...);
    index_parameter(new_subcommand);
    return m_subcommands.back();
  }

  template <typename... Args>
  auto add_option(Args&&... p_names) -> option& {
    auto new_option = m_options.emplace(std::cend(m_options), std::forward<Args>(p_names)...);
    index_parameter(new_option);
    return m_options.back();
  }

  auto add_action(callback p_action) -> command&;

  auto get_subcommand(std::string_view p_sv) -> command&;

  auto get_option(std::string_view p_sv) -> option&;

  // parse() constructs an Action object containing the callable object
  // and the parameters to provide to it. All parameters are provided as
  // strings on the command line, so they are provided as strings to the
  // callable object.
  int run(std::span<std::string_view> p_args);

private:
  [[nodiscard]] inline auto is_invoked_command(std::string_view p_name) const -> bool;

  callback& parse(std::span<std::string_view> p_args, parameters& p_params);

  template <typename Iterator>
  void index_parameter(Iterator p_param_iter) {
    for (auto const& name : p_param_iter->names()) {
      m_str_to_param_map.insert_or_assign(name, p_param_iter);
    }
  }

}; // class Command

} // namespace ogre
