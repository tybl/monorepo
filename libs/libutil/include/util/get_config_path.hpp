// License: The Unlicense (https://unlicense.org)
#pragma once

#include <filesystem>

namespace tybl::util {

auto get_config_path(std::string const& app_name) -> std::filesystem::path;

} // namespace tybl::util
