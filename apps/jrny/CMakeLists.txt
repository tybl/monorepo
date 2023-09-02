################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.13)

project(jrny
	VERSION 0.1.0
	DESCRIPTION "Simple note capture utility"
	LANGUAGES CXX)

find_package(tomlplusplus REQUIRED)

add_executable(jrny)
target_compile_features(jrny PRIVATE cxx_std_20) # std::span
target_link_libraries(jrny PRIVATE libutil::util tomlplusplus)
target_sources(jrny PRIVATE src/jrny.cpp)
