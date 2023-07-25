#pragma once

#include <filesystem>

namespace tybl::util {

auto get_home_path() -> std::filesystem::path;

auto get_config_path(std::string const& app_name) -> std::filesystem::path;

} // namespace tybl::util
