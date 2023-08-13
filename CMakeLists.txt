################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet:ts=2
################################################################################
cmake_minimum_required(VERSION 3.21)

project(pnt
	VERSION 0.0.0
	DESCRIPTION "A collection of libraries and utilities for manipulating position, navigation, and time data"
	LANGUAGES CXX)

if(PROJECT_IS_TOP_LEVEL)
	include(CTest)
  find_package(doctest)
	add_subdirectory(utils/doctest)
endif()

# Define C++ dialect
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

# Prepare dependencies
set(CMAKE_PREFIX_PATH deps)

# Define build
add_subdirectory(libs)
