################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################

add_executable(cli)
target_link_libraries(cli PRIVATE compiler_settings ttt)
target_sources(cli
        PRIVATE
        src/game.cpp
        src/main.cpp
        )
