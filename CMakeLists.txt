################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet:ts=2
################################################################################
cmake_minimum_required(VERSION 3.14)

project(pnt
	VERSION 0.0.0
	DESCRIPTION "A collection of libraries and utilities for manipulating position, navigation, and time data"
	LANGUAGES CXX)

# Define C++ dialect
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

# Prepare dependencies
set(CMAKE_PREFIX_PATH deps)
find_package(doctest)

# Enable testing
include(CTest)
add_subdirectory(utils/doctest)

# Define build
add_subdirectory(libs)
