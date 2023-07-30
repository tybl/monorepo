################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################
cmake_minimum_required(VERSION 3.14)

project(MaxRunStats
  VERSION 0.0.1
  DESCRIPTION "Parse TCS files into a CSV file that contains your best time for all distances"
  LANGUAGES CXX)

find_package(date REQUIRED)
find_package(pugixml REQUIRED)

add_executable(extract_stats)
target_compile_features(extract_stats PRIVATE cxx_std_20) # std::map::contains()
target_link_libraries(extract_stats PRIVATE date::date pugixml::pugixml)
target_sources(extract_stats PRIVATE src/main.cpp)
