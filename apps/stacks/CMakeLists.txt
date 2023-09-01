################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.18)

project(stacks
	VERSION 1.0.0
	DESCRIPTION ""
	LANGUAGES CXX)

find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

add_executable(stacksolve)
target_link_libraries(stacksolve PRIVATE stacksolvelib)
target_sources(stacksolve PRIVATE src/main.cpp)
