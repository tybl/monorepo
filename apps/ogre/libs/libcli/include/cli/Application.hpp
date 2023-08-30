// License: The Unlicense (https://unlicense.org)
#pragma once

#include "Command.hpp"

#include <string_view>
#include <vector>

namespace ogre {

class application {
  command m_command;
  std::string_view m_version;

public:
  application(std::string_view p_name, std::string_view p_version)
    : m_command(p_name)
    , m_version(p_version) {
    // The ctor receives the app name and version. It doesn't receive the
    // command-line arguments. As such, it is not aware of any overridden
    // configuration values.
    m_command.add_option("-v", "--version").add_help("Displays the version and exits");
    m_command.add_subcommand("add").add_help("").add_action([](parameters const&) -> int { return 0; });
  }

  auto run(int p_argc, char const* p_argv[]) -> int {
    std::vector<std::string_view> args(p_argv, p_argv + p_argc);
    return m_command.run(args);
  }

}; // class application

} // namespace ogre
