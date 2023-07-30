################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################
cmake_minimum_required(VERSION 3.14) # FetchContent_MakeAvailable

project(MaxRunStats
  VERSION 0.0.1
  DESCRIPTION "Parse TCS files into a CSV file that contains your best time for all distances"
  LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
  include(util/cmake/CompilerSettings.cmake)
  include(util/cmake/Linters.cmake)
endif()

find_package(date REQUIRED)
find_package(pugixml REQUIRED)

add_executable(extract_stats)
target_link_libraries(extract_stats PRIVATE compiler_settings date::date pugixml::pugixml)
target_sources(extract_stats PRIVATE src/main.cpp)
