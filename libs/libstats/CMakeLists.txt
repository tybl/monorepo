################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################

add_library(stats INTERFACE)
target_include_directories(stats INTERFACE include)
target_link_libraries(stats INTERFACE compiler_settings)
target_sources(stats INTERFACE include/stats/distribution.hpp)

add_executable(test_libstats)
target_link_libraries(test_libstats
  PRIVATE
    test_base
    stats
)
target_sources(test_libstats
  PRIVATE
    test/distribution.cpp
)
add_test(NAME libstats_test COMMAND test_libstats)
