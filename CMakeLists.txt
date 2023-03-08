################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################
cmake_minimum_required(VERSION 3.18)

project(TicTacToe
	VERSION 0.0.0
	LANGUAGES CXX)

include(CTest)
include(utils/cmake/CompilerSettings.cmake)
include(utils/cmake/Linters.cmake)

find_package(Boost REQUIRED)
find_package(doctest REQUIRED)
find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)

add_subdirectory(utils/doctest)
add_subdirectory(libs)
add_subdirectory(apps)
