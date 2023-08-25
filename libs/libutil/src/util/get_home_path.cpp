// License: The Unlicense (https://unlicense.org)
#include "util/get_config_path.hpp"

#include <cstdlib>  // std::getenv
#include <pwd.h>    // getpwuid
#include <unistd.h> // getuid

namespace tybl::util {

auto get_home_path() -> std::filesystem::path {
  char const* home_path_p = std::getenv("HOME");
  if (nullptr == home_path_p) {
    home_path_p = ::getpwuid(::getuid())->pw_dir;
  }
  return std::filesystem::path(home_path_p);
}

} // namespace tybl::util
