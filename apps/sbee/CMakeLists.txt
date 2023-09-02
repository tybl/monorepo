################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.18)

project(sbee
	VERSION 1.0.0
	DESCRIPTION "NYTimes Spelling Bee solver"
	LANGUAGES CXX)

find_package(fmt REQUIRED)

# TODO(tybl): Check sbee functionality to see if this can be removed
add_executable(prune)
target_compile_features(prune PRIVATE cxx_std_20) # std::span
target_sources(prune PRIVATE src/prune.cpp)

add_executable(sbee)
target_compile_features(sbee PRIVATE cxx_std_20) # std::span
target_link_libraries(sbee PRIVATE fmt::fmt sbeelib)
target_link_options(sbee PRIVATE $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
target_sources(sbee PRIVATE src/sbee.cpp)
