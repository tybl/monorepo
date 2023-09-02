################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.21)

project(TaskOgre
  VERSION 0.0.0
  DESCRIPTION "Taskwarrior clone"
  LANGUAGES CXX)

add_executable(task)
target_compile_definitions(task
  PRIVATE
    -DPROJECT_NAME="${CMAKE_PROJECT_NAME}"
    -DPROJECT_VERSION="${CMAKE_PROJECT_VERSION}")
target_link_libraries(task PRIVATE libcli libuuid)
target_sources(task
  PRIVATE
    apps/task/src/main.cpp)
