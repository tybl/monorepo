#pragma once

#include <filesystem>

auto get_home_path() -> std::filesystem::path;

auto get_config_path(std::string const& app_name) -> std::filesystem::path;
