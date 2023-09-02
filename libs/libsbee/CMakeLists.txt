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

add_library(sbeelib)
target_compile_features(sbeelib PUBLIC cxx_std_20) # std::span
target_include_directories(sbeelib PUBLIC include)
target_link_options(sbeelib PUBLIC $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
target_sources(sbeelib
	PRIVATE
		src/recommendation_engine.cpp
	PUBLIC
		include/sbee/recommendation_engine.hpp)

add_executable(test_sbeelib)
target_link_libraries(test_sbeelib PRIVATE sbeelib test_main)
target_link_options(test_sbeelib PUBLIC $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
target_sources(test_sbeelib
	PRIVATE
		test/recommendation_engine.cpp)
add_test(NAME sbeelib_test COMMAND test_sbeelib)
