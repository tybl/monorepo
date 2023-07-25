################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.21...3.25)

project(libutil
	VERSION 0.1.0
	DESCRIPTION "Reusable code that I couldn't find another library for"
	LANGUAGES CXX)

if(PROJECT_IS_TOP_LEVEL)
	include(CTest)
endif()

add_library(util)
target_include_directories(util PUBLIC include)
target_sources(util
	PRIVATE
		src/util/get_config_path.cpp)

