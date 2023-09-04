################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################

add_executable(stacksolve)
target_link_libraries(stacksolve PRIVATE stacksolvelib)
target_sources(stacksolve PRIVATE src/main.cpp)
