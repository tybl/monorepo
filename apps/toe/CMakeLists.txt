################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################

add_executable(toe)
target_link_libraries(toe
  PRIVATE
    compiler_settings
    fmt
    nlohmann_json
    ttt)
target_sources(toe
  PRIVATE
    src/main.cpp
    src/server.cpp
)

add_executable(test_search)
target_link_libraries(test_search PRIVATE compiler_settings stats test_base ttt)
target_sources(test_search
  PRIVATE
    src/search_moves.cpp)
add_test(NAME search_test COMMAND test_search)
