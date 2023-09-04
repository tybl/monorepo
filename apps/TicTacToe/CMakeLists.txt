################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################

add_executable(cli)
target_link_libraries(cli PRIVATE ttt tttai)
target_sources(cli
	PRIVATE
		src/cli/game.cpp
		src/cli/main.cpp)

#[[
# TODO(tybl): boost asio appears to have a null dereference
add_executable(toe)
target_link_libraries(toe PRIVATE fmt::fmt nlohmann_json ttt tttai)
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
