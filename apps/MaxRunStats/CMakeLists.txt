################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################

find_package(date REQUIRED)
find_package(pugixml REQUIRED)

add_executable(extract_stats)
target_compile_features(extract_stats PRIVATE cxx_std_20) # std::map::contains()
target_link_libraries(extract_stats PRIVATE date::date pugixml::pugixml)
target_sources(extract_stats PRIVATE src/main.cpp)
