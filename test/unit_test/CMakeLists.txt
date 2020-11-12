################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################
cmake_minimum_required(VERSION 3.14) # FetchContent_MakeAvailable

# Define unittests executable target
add_executable(unit_test main.cpp)
target_link_libraries(unit_test PRIVATE compiler_settings doctest::doctest)
add_test(NAME unit_test_t COMMAND unit_test)
