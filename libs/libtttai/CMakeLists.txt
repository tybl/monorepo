################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.21)

project(libtttai
	VERSION 1.0.0
	DESCRIPTION "Command-line Tic-Tac-Toe"
	LANGUAGES CXX)

find_package(fmt REQUIRED)

add_library(tttai)
target_include_directories(tttai PUBLIC include)
target_link_libraries(tttai PRIVATE fmt ttt)
target_sources(tttai
	PRIVATE
		src/get_best_move.cpp)

add_executable(test_libtttai)
target_link_libraries(test_libtttai PRIVATE fmt test_main ttt tttai)
target_sources(test_libtttai
	PRIVATE
		test/get_best_move.cpp)
add_test(NAME libtttai_test COMMAND test_libtttai)
