cmake_minimum_required(VERSION 3.14)

project(pnt_dependencies)

include(ExternalProject)

ExternalProject_Add(doctest
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR> -DDOCTEST_WITH_TESTS=OFF
  GIT_REPOSITORY https://github.com/onqtam/doctest.git
  INSTALL_DIR ${CMAKE_SOURCE_DIR})