################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.21...3.25)

project(argcplusplus
	VERSION 0.0.0
	DESCRIPTION "To(o) advance(d) parameter passing for C++ programs"
	LANGUAGES CXX)

if(PROJECT_IS_TOP_LEVEL)
	find_package(doctest REQUIRED)
	include(CTest)
endif()

add_library(argcplusplus)
target_include_directories(argcplusplus PUBLIC include)
target_sources(argcplusplus
	PUBLIC
		include/parm/Application.hpp
		include/parm/Parameter.hpp
	PRIVATE
		src/parm/Application.cpp
)

if(PROJECT_IS_TOP_LEVEL)
	# TODO(tybl): Create unit tests
endif()
