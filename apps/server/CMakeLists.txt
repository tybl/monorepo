################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################

add_executable(tictac)
target_link_libraries(tictac PRIVATE ttt)
target_sources(tictac PRIVATE src/serv.cpp)
