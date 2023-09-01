################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.21)

project(TicTacToe
	VERSION 1.0.0
	DESCRIPTION "Command-line Tic-Tac-Toe"
	LANGUAGES CXX)

find_package(Boost REQUIRED)
find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(cli)
target_link_libraries(cli PRIVATE ttt tttai)
target_sources(cli
	PRIVATE
		src/cli/game.cpp
		src/cli/main.cpp)

#[[
# TODO(tybl): boost asio appears to have a null dereference
add_executable(toe)
target_link_libraries(toe
	PRIVATE
		fmt
		nlohmann_json
		ttt
		tttai)
target_sources(toe
	PRIVATE
		src/toe/main.cpp
		src/toe/server.cpp)
]]

add_executable(test_search)
target_link_libraries(test_search PRIVATE stats test_main ttt)
target_sources(test_search
	PRIVATE
		test/toe/search_moves.cpp)
add_test(NAME search_test COMMAND test_search)
