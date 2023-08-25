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
	add_subdirectory(util/doctest)
endif()

add_library(libnmea)
target_compile_features(libnmea PRIVATE cxx_std_20)
target_compile_options(libnmea PUBLIC $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
target_include_directories(libnmea PUBLIC include)
target_sources(libnmea PRIVATE src/nmea/parse.cpp)

add_executable(test_libnmea)
target_link_libraries(test_libnmea PRIVATE libnmea test_main)
target_link_options(test_libnmea PRIVATE $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
target_sources(test_libnmea PRIVATE test/nmea/parse.cpp)
add_test(NAME libnmea_test COMMAND test_libnmea)
