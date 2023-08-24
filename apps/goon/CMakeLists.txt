################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################
cmake_minimum_required(VERSION 3.13)

# Describe the project
project(goon
	VERSION 0.0.1
	DESCRIPTION "Astroids clone"
	LANGUAGES CXX)

# Describe executable
add_executable(goon)
target_sources(goon
	PRIVATE
		src/Dispatcher.cpp
		src/Widget.cpp
		src/Window.cpp
		src/main.cpp)
target_include_directories(goon PUBLIC src)
target_link_libraries(goon SDL2)
set_target_properties(goon PROPERTIES
	CXX_STANDARD 20
	CXX_EXTENSIONS NO)
