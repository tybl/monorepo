################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.21)

project(libttt
	VERSION 1.0.0
	DESCRIPTION "Command-line Tic-Tac-Toe"
	LANGUAGES CXX)

find_package(fmt REQUIRED)

add_library(ttt)
target_include_directories(ttt PUBLIC include)
target_link_libraries(ttt PRIVATE fmt)
target_sources(ttt
	PRIVATE
		src/board.cpp
		src/cell.cpp
		src/move.cpp)

add_executable(test_libttt)
target_link_libraries(test_libttt PRIVATE fmt test_main ttt)
target_sources(test_libttt
	PRIVATE
		test/ttt/board.cpp
		test/ttt/cell.cpp)
add_test(NAME libttt_test COMMAND test_libttt)
