################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.14) # FetchContent_MakeAvailable

project(jrny
	VERSION 0.1.0
	LANGUAGES CXX)

find_package(tomlplusplus REQUIRED)

include(FetchContent)

FetchContent_Declare(
	libutil
	GIT_REPOSITORY gitea@bitute.lan:tybl/libutil.git
	GIT_TAG        main
	GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(libutil)

add_subdirectory(apps)
