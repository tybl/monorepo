################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################

add_executable(extract_stats)
target_link_libraries(extract_stats PRIVATE compiler_settings pugixml)
target_sources(extract_stats PRIVATE extract_stats/main.cpp)
