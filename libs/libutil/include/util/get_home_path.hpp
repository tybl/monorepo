// License: The Unlicense (https://unlicense.org)
#pragma once

#include <filesystem>

namespace tybl::util {

auto get_home_path() -> std::filesystem::path;

} // namespace tybl::util
