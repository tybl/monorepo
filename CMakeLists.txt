################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################
cmake_minimum_required(VERSION 3.14) # FetchContent_MakeAvailable

project(MaxRunStats
  VERSION 0.0.1
  DESCRIPTION "Parse TCS files into a CSV file that contains your best time for all distances"
  LANGUAGES CXX)

option(BUILD_ALL_TESTS "Build and run tests as a subproject" OFF)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
endif()
include(FetchContent)
include(util/cmake/CompilerSettings.cmake)
include(util/cmake/Linters.cmake)

# Use doctest as unit test framework
FetchContent_Declare(doctest
  GIT_REPOSITORY https://github.com/onqtam/doctest.git
  GIT_SHALLOW    TRUE
  GIT_TAG        "2.4.1")
FetchContent_MakeAvailable(doctest)

# Use pugixml to parse XML
FetchContent_Declare(pugixml
  GIT_REPOSITORY https://github.com/zeux/pugixml.git
  GIT_SHALLOW    TRUE
  GIT_TAG        "v1.10")
FetchContent_MakeAvailable(pugixml)

add_subdirectory(app)

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) OR BUILD_ALL_TESTS)
  add_subdirectory(test)
endif()
