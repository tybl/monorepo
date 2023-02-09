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

add_executable(toe2)
target_link_libraries(toe2 PRIVATE compiler_settings fmt ttt)
target_sources(toe2
  PRIVATE
    src/main.cpp
)
