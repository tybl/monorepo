################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.13)

project(goon
	VERSION 0.0.1
	DESCRIPTION "Astroids clone"
	LANGUAGES CXX)

find_package(SDL2 REQUIRED)

add_executable(goon)
target_include_directories(goon PRIVATE src)
target_link_libraries(goon PRIVATE SDL2)
target_sources(goon
	PRIVATE
		src/Dispatcher.cpp
		src/Widget.cpp
		src/Window.cpp
		src/main.cpp)
