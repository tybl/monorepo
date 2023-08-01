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

add_executable(prune)
target_compile_features(prune PRIVATE cxx_std_20) # std::span
target_sources(prune PRIVATE src/prune.cpp)

add_library(sbeelib)
target_sources(sbeelib
	PRIVATE
		src/recommendation_engine.cpp
	PUBLIC
		src/recommendation_engine.hpp)

add_executable(sbee)
# TODO(tybl): Utilize std::string::contains(), when cxx_std_23 is available
target_compile_features(sbee PRIVATE cxx_std_20) # std::span
target_link_libraries(sbee PRIVATE fmt sbeelib)
target_sources(sbee PRIVATE src/sbee.cpp)
