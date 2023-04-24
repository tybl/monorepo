################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################

add_library(tttai)
target_include_directories(tttai PUBLIC include)
target_link_libraries(tttai PRIVATE compiler_settings fmt ttt)
target_sources(tttai
        PRIVATE
        src/get_best_move.cpp)

add_executable(test_libtttai)
target_include_directories(test_libtttai PUBLIC include)
target_link_libraries(test_libtttai PRIVATE compiler_settings fmt test_base ttt tttai)
target_sources(test_libtttai
        PRIVATE
        test/get_best_move.cpp)
add_test(NAME libtttai_test COMMAND test_libtttai)
