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
	find_package(doctest REQUIRED)
	include(CTest)
endif()

add_library(util)
add_library(libutil::util ALIAS util)
target_include_directories(util PUBLIC include)
target_sources(util
	PRIVATE
		src/util/crc32.cpp
		src/util/get_config_path.cpp
		src/util/get_home_path.cpp)

if(PROJECT_IS_TOP_LEVEL)
	add_executable(test_libutil)
	target_link_libraries(test_libutil PRIVATE util doctest::doctest)
	target_sources(test_libutil
		PRIVATE
		test/util/crc32.cpp
		test/util/main.cpp
		test/util/string_contains.cpp)

	add_test(NAME libutil_test COMMAND test_libutil)
endif()
