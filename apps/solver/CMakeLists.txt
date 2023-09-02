################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.22)

project(solve
    VERSION 0.0.0
    DESCRIPTION "CLI math solver"
    LANGUAGES CXX)

# TODO(tybl): Create library with unit tests
add_executable(solve)
target_compile_features(solve PRIVATE cxx_std_20)
target_sources(solve
    PRIVATE
        src/Scanner.cpp
        src/Solve.cpp
        src/Token.cpp
        src/main.cpp)
