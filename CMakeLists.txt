################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.18)

project(monorepo
	VERSION 0.2.0
	DESCRIPTION "Collection of C++ libraries, applications and tools written by me"
	LANGUAGES CXX)

find_package(doctest REQUIRED)

include(CTest)
include(utils/cmake/CompilerSettings.cmake)
add_subdirectory(utils/doctest)

add_subdirectory(libs/libargc)
add_subdirectory(libs/liblynel)
add_subdirectory(libs/libcoord)
add_subdirectory(libs/libutil)
add_subdirectory(libs/libpnt)
add_subdirectory(libs/libstats)
add_subdirectory(libs/libuuid)
add_subdirectory(libs/libcli)
add_subdirectory(libs/libsbee)
add_subdirectory(apps/MaxRunStats)
add_subdirectory(apps/goon)
add_subdirectory(apps/jrny)
add_subdirectory(apps/ogre)
add_subdirectory(apps/sbee)
add_subdirectory(apps/solver)
add_subdirectory(apps/stacks)
add_subdirectory(apps/TicTacToe)
