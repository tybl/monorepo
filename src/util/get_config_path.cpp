#include "util/get_config_path.hpp"

#include "util/get_home_path.hpp"

#include <cstdlib>

namespace tybl::util {

auto get_config_path(std::string const& p_app_name) -> std::filesystem::path {
  std::filesystem::path result;
  char const* config_path_cstr_p = std::getenv("XDG_CONFIG_HOME");
  if (nullptr != config_path_cstr_p) {
    result = config_path_cstr_p;
  } else {
    result = get_home_path() / ".config";
  }
  result /= p_app_name;
  return result;
}

} // namespace tybl::util
