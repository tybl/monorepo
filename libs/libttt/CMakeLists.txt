################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################

find_package(fmt REQUIRED)

add_library(ttt)
target_include_directories(ttt PUBLIC include)
target_link_libraries(ttt PUBLIC fmt::fmt)
target_sources(ttt
	PRIVATE
		src/ttt/board.cpp
		src/ttt/cell.cpp
		src/ttt/move.cpp)

add_executable(test_libttt)
target_link_libraries(test_libttt PRIVATE test_main ttt)
target_sources(test_libttt
	PRIVATE
		test/ttt/board.cpp
		test/ttt/cell.cpp)
add_test(NAME libttt_test COMMAND test_libttt)
