################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.21...3.25)

project(libstats
	VERSION 1.0.0
	DESCRIPTION "Useful class for pulling statistics from a distribution"
	LANGUAGES CXX)

if(PROJECT_IS_TOP_LEVEL)
	include(CTest)
	find_package(doctest REQUIRED)
	add_subdirectory(util/doctest)
endif()

add_library(stats INTERFACE)
target_include_directories(stats INTERFACE include)
target_sources(stats INTERFACE include/stats/distribution.hpp)

add_executable(test_libstats)
target_link_libraries(test_libstats PRIVATE stats test_main)
target_sources(test_libstats PRIVATE test/distribution.cpp)

add_test(NAME libstats_test COMMAND test_libstats)
