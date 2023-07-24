################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################
cmake_minimum_required(VERSION 3.1)

project(jrny
	VERSION 0.0.0
	LANGUAGES CXX)

find_package(tomlplusplus REQUIRED)

add_subdirectory(apps)
