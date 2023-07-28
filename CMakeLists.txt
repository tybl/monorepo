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
		include/argc++/Application.hpp
		include/argc++/Parameter.hpp
	PRIVATE
		src/argc++/Application.cpp
)

if(PROJECT_IS_TOP_LEVEL)
	# TODO(tybl): Create unit tests
	add_executable(test_argcplusplus)
	target_link_libraries(test_argcplusplus PRIVATE argcplusplus doctest::doctest)
	target_sources(test_argcplusplus
		PRIVATE
			test/argc++/main.cpp
			test/argc++/test_help.cpp)
	add_test(NAME argcplusplus_test COMMAND test_argcplusplus)
endif()
