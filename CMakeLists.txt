################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.18)

project(sbee
	VERSION 1.0.0
	DESCRIPTION ""
	LANGUAGES CXX)

find_package(fmt REQUIRED)

if(PROJECT_IS_TOP_LEVEL)
	include(CTest)

	find_package(doctest REQUIRED)
	add_subdirectory(util/doctest)
endif()

add_executable(prune)
target_compile_features(prune PRIVATE cxx_std_20) # std::span
target_sources(prune PRIVATE src/prune.cpp)

add_library(sbeelib)
target_compile_features(sbeelib PUBLIC cxx_std_20) # std::span
target_include_directories(sbeelib PUBLIC src)
target_sources(sbeelib
	PRIVATE
		src/recommendation_engine.cpp
	PUBLIC
		src/recommendation_engine.hpp)

add_executable(test_sbeelib)
target_link_libraries(test_sbeelib PRIVATE sbeelib test_main)
target_sources(test_sbeelib
	PRIVATE
		test/recommendation_engine.cpp)
add_test(NAME sbeelib_test COMMAND test_sbeelib)

add_executable(sbee)
target_compile_features(sbee PRIVATE cxx_std_20) # std::span
target_link_libraries(sbee PRIVATE fmt::fmt sbeelib)
target_sources(sbee PRIVATE src/sbee.cpp)
