################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.18)

project(BeeKiller
	VERSION 0.0.0
	LANGUAGES CXX)

find_package(fmt REQUIRED)

add_executable(prune)
target_compile_features(prune PRIVATE cxx_std_20) # std::span
target_sources(prune PRIVATE src/prune.cpp)

add_executable(rec)
# TODO(tybl): Utilize std::string::contains(), when cxx_std_23 is available
target_compile_features(prune PRIVATE cxx_std_20) # std::span
target_link_libraries(rec PRIVATE fmt)
target_sources(rec PRIVATE src/rec.cpp)
