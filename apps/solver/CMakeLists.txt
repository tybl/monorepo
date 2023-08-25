cmake_minimum_required(VERSION 3.22)

project(solve LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(solve)
target_sources(solve
    PRIVATE
        src/Scanner.cpp
        src/Solve.cpp
        src/Token.cpp
        src/main.cpp)
