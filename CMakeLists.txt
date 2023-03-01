################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################
cmake_minimum_required(VERSION 3.18)

project(TicTacToe
	VERSION 0.0.0
	LANGUAGES CXX)

include(FetchContent)
include(utils/cmake/CompilerSettings.cmake)
include(utils/cmake/Linters.cmake)

if(CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
endif()

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_SHALLOW    TRUE
  GIT_TAG        a33701196adfad74917046096bf5a2aa0ab0bb50)
FetchContent_MakeAvailable(fmt)
FetchContent_Declare(nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_SHALLOW    TRUE
  GIT_TAG        bc889afb4c5bf1c0d8ee29ef35eaaf4c8bef8a5d)
FetchContent_MakeAvailable(nlohmann_json)

add_subdirectory(libs)
add_subdirectory(apps)
