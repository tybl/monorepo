cmake_minimum_required(VERSION 3.14)

project(pnt_dependencies)

include(ExternalProject)

ExternalProject_Add(doctest
  CMAKE_ARGS     -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
                 -DDOCTEST_WITH_TESTS=OFF
  GIT_REPOSITORY https://github.com/onqtam/doctest.git
  GIT_SHALLOW    TRUE
  GIT_TAG        ae7a13539fb71f270b87eb2e874fbac80bc8dda2 # v2.4.11
  INSTALL_DIR ${CMAKE_BINARY_DIR})
