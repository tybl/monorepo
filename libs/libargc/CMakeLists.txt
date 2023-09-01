################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.21...3.25)

project(argcplusplus
	VERSION 0.0.0
	DESCRIPTION "To(o) advance(d) parameter passing for C++ programs"
	LANGUAGES CXX)

find_package(fmt REQUIRED)

add_library(argcplusplus)
target_compile_features(argcplusplus PUBLIC cxx_std_20)
target_include_directories(argcplusplus PUBLIC include)
target_link_libraries(argcplusplus PUBLIC fmt::fmt)
target_sources(argcplusplus
	PUBLIC
		include/argc++/Application.hpp
		include/argc++/Argument.hpp
	PRIVATE
		src/argc++/Application.cpp
		src/argc++/Argument.cpp)

add_executable(test_argcplusplus)
target_link_libraries(test_argcplusplus PRIVATE argcplusplus doctest::doctest)
target_sources(test_argcplusplus
	PRIVATE
		test/argc++/main.cpp
		test/argc++/test_help.cpp
		test/argc++/test_version.cpp)
add_test(NAME argcplusplus_test COMMAND test_argcplusplus)
