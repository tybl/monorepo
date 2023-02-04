################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################

add_library(ttt)
target_include_directories(ttt PUBLIC include)
target_sources(ttt PRIVATE src/tictactoe.cpp)
