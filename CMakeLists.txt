################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################
cmake_minimum_required(VERSION 3.18)

project(TicTacToe
	VERSION 0.0.0
	LANGUAGES CXX)

include(utils/cmake/CompilerSettings.cmake)
include(utils/cmake/Linters.cmake)

add_subdirectory(libs)
add_subdirectory(apps)
