#include "util/get_config_path.hpp"

#include <pwd.h>
#include <unistd.h>

namespace tybl::util {

auto get_home_path() -> std::filesystem::path {
  char const* home_path_p = nullptr;
  if (nullptr == (home_path_p = ::getenv("HOME"))) {
    home_path_p = ::getpwuid(::getuid())->pw_dir;
  }
  return std::filesystem::path(home_path_p);
}

auto get_config_path(std::string const& p_app_name) -> std::filesystem::path {
  std::filesystem::path result;
  char const* config_path_cstr_p = ::getenv("XDG_CONFIG_HOME");
  if (nullptr != config_path_cstr_p) {
    result = config_path_cstr_p;
  } else {
    result = std::filesystem::path(get_home_path()) / ".config";
  }
  result /= p_app_name;
  return result;
}

} // namespace tybl::util
