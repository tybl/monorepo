################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################
cmake_minimum_required(VERSION 3.21)

project(TicTacToe
	VERSION 1.0.0
	DESCRIPTION "Command-line Tic-Tac-Toe"
	LANGUAGES CXX)

if(PROJECT_IS_TOP_LEVEL)
	include(CTest)
	find_package(doctest REQUIRED)
	add_subdirectory(util/doctest)

	include(FetchContent)
	FetchContent_Declare(
		libstats
		GIT_REPOSITORY git@github.com:tybl/libstats.git
		GIT_TAG        dev
		GIT_SHALLOW    TRUE
	)
	FetchContent_MakeAvailable(libstats)
endif()

find_package(Boost REQUIRED)
find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)

add_library(ttt)
target_include_directories(ttt PUBLIC include)
target_link_libraries(ttt PRIVATE fmt)
target_sources(ttt
        PRIVATE
        src/ttt/board.cpp
        src/ttt/cell.cpp
        src/ttt/move.cpp)

add_executable(test_libttt)
target_link_libraries(test_libttt PRIVATE fmt test_main ttt)
target_sources(test_libttt
        PRIVATE
        test/ttt/board.cpp
        test/ttt/cell.cpp)
add_test(NAME libttt_test COMMAND test_libttt)

add_library(tttai)
target_include_directories(tttai PUBLIC include)
target_link_libraries(tttai PRIVATE fmt ttt)
target_sources(tttai
        PRIVATE
        src/tttai/get_best_move.cpp)

add_executable(test_libtttai)
target_link_libraries(test_libtttai PRIVATE fmt test_main ttt tttai)
target_sources(test_libtttai
        PRIVATE
        test/tttai/get_best_move.cpp)
add_test(NAME libtttai_test COMMAND test_libtttai)

add_executable(cli)
target_link_libraries(cli PRIVATE ttt tttai)
target_sources(cli
        PRIVATE
        src/cli/game.cpp
        src/cli/main.cpp
        )

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
        src/toe/server.cpp
        )

add_executable(test_search)
target_link_libraries(test_search PRIVATE stats test_main ttt)
target_sources(test_search
        PRIVATE
        test/toe/search_moves.cpp)
add_test(NAME search_test COMMAND test_search)
