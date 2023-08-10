################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet:ts=2
################################################################################

add_library(test_main)
target_link_libraries(test_main PUBLIC doctest::doctest)
target_sources(test_main PRIVATE src/main.cpp)
