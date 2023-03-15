################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################

add_library(ttt)
target_include_directories(ttt PUBLIC include)
target_link_libraries(ttt PRIVATE compiler_settings fmt)
target_sources(ttt
  PRIVATE
        src/board.cpp
        src/get_best_move.cpp
        src/move.cpp
        src/tictactoe.cpp)

add_executable(test_libttt)
target_include_directories(test_libttt PUBLIC include)
target_link_libraries(test_libttt PRIVATE compiler_settings fmt test_base ttt)
target_sources(test_libttt
  PRIVATE
        test/board.cpp
        test/get_best_move.cpp)
add_test(NAME libttt_test COMMAND test_libttt)
