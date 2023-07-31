################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.18)

project(sbee
	VERSION 0.0.0
	DESCRIPTION ""
	LANGUAGES CXX)

find_package(fmt REQUIRED)

add_executable(prune)
target_compile_features(prune PRIVATE cxx_std_20) # std::span
target_sources(prune PRIVATE src/prune.cpp)

add_executable(sbee)
# TODO(tybl): Utilize std::string::contains(), when cxx_std_23 is available
target_compile_features(sbee PRIVATE cxx_std_20) # std::span
target_link_libraries(sbee PRIVATE fmt)
target_sources(sbee PRIVATE src/sbee.cpp)
