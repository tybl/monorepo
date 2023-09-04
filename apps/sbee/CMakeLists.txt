################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################

find_package(fmt REQUIRED)

# TODO(tybl): Check sbee functionality to see if this can be removed
add_executable(prune)
target_compile_features(prune PRIVATE cxx_std_20) # std::span
target_sources(prune PRIVATE src/prune.cpp)

add_executable(sbee)
target_compile_features(sbee PRIVATE cxx_std_20) # std::span
target_link_libraries(sbee PRIVATE fmt::fmt sbeelib)
target_link_options(sbee PRIVATE $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
target_sources(sbee PRIVATE src/sbee.cpp)
