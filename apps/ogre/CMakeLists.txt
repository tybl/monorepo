################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.21)

project(TaskOgre
  VERSION 0.0.0
  DESCRIPTION "Taskwarrior clone"
  LANGUAGES CXX)

find_package(doctest REQUIRED)
find_package(fmt REQUIRED)

if(PROJECT_IS_TOP_LEVEL)
  include(CTest)

  add_subdirectory(utils/doctest)
endif()

add_subdirectory(apps)
