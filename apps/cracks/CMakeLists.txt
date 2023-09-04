################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################

find_package(fmt REQUIRED)

add_executable(sudoku)
target_link_libraries(sudoku PRIVATE fmt::fmt)
target_link_options(sudoku PRIVATE $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
target_sources(sudoku PRIVATE src/sudoku.cpp)

add_executable(wordle)
target_link_libraries(wordle PRIVATE fmt::fmt)
target_link_options(wordle PRIVATE $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
target_sources(wordle PRIVATE src/wordle.cpp)
