################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################

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
