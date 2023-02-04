################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################

add_executable(toe)
target_link_libraries(toe PRIVATE ttt)
target_sources(toe PRIVATE src/cli.cpp)
