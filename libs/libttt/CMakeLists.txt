################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################

add_library(ttt)
target_include_directories(ttt PUBLIC include)
target_link_libraries(ttt PRIVATE compiler_settings fmt)
target_sources(ttt
  PRIVATE
        src/board.cpp
        src/move.cpp
        src/tictactoe.cpp)
