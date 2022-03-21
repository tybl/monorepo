# License: The Unlicense (https://unlicense.org)
cmake_minimum_required(VERSION 3.14)

project(pnt
	VERSION 0.0.0
	DESCRIPTION "A collection of libraries and utilities for manipulating position, navigation, and time data"
	LANGUAGES CXX)

include(CTest)
include(utils/cmake/external_libraries.cmake)

add_subdirectory(utils/doctest)