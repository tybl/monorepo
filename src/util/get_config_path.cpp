#include "util/get_config_path.hpp"

#include <pwd.h>
#include <unistd.h>

namespace tybl::util {

auto get_home_path() -> std::filesystem::path {
  char const* home_path = nullptr;
  if (nullptr == (home_path = getenv("HOME"))) {
    home_path = getpwuid(getuid())->pw_dir;
  }
  return std::filesystem::path(home_path);
}

auto get_config_path(std::string const& app_name) -> std::filesystem::path {
  std::filesystem::path result;
  char const* config_path_cstr = getenv("XDG_CONFIG_HOME");
  if (nullptr != config_path_cstr) {
    result = config_path_cstr;
  } else {
    result = std::filesystem::path(get_home_path()) / ".config";
  }
  result /= app_name;
  return result;
}

} // namespace tybl::util
