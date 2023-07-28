################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################
cmake_minimum_required(VERSION 3.18)

project(BeeKiller
	VERSION 0.0.0
	LANGUAGES CXX)

include(util/cmake/CompilerSettings.cmake)
include(util/cmake/Linters.cmake)

find_package(fmt REQUIRED)

add_executable(prune)
target_compile_features(prune PRIVATE cxx_std_20) # std::span
target_link_libraries(prune PRIVATE compiler_settings fmt)
target_sources(prune PRIVATE src/prune.cpp)

add_executable(rec)
target_compile_features(prune PRIVATE cxx_std_20) # std::string::contains()
target_link_libraries(rec PRIVATE compiler_settings fmt)
target_sources(rec PRIVATE src/rec.cpp)
