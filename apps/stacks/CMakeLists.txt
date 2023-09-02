################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.13)

project(stacks
	VERSION 1.0.0
	DESCRIPTION "Solver for color matching stack games"
	LANGUAGES CXX)

add_executable(stacksolve)
target_link_libraries(stacksolve PRIVATE stacksolvelib)
target_sources(stacksolve PRIVATE src/main.cpp)
