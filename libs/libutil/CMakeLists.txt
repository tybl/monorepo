################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet:ts=2
################################################################################
cmake_minimum_required(VERSION 3.21...3.25)

project(libutil
	VERSION 0.1.0
	DESCRIPTION "Reusable code that I couldn't find another library for"
	LANGUAGES CXX)

add_library(util)
add_library(libutil::util ALIAS util)
target_include_directories(util PUBLIC include)
target_sources(util
	PRIVATE
		src/util/crc32.cpp
		src/util/get_config_path.cpp
		src/util/get_home_path.cpp)

add_executable(test_libutil)
target_link_libraries(test_libutil PRIVATE test_main util)
target_sources(test_libutil
	PRIVATE
		test/util/crc32.cpp
		test/util/string_contains.cpp)
add_test(NAME libutil_test COMMAND test_libutil)
