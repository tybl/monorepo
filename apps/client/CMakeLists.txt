################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################

add_executable(toe)
target_link_libraries(toe PRIVATE compiler_settings ttt)
target_sources(toe
  PRIVATE
    src/cli.cpp
    src/socket.cpp
)
