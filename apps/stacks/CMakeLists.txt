################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################
cmake_minimum_required(VERSION 3.18)

project(stacks
	VERSION 1.0.0
	DESCRIPTION ""
	LANGUAGES CXX)

if(PROJECT_IS_TOP_LEVEL)
	include(CTest)
	find_package(doctest REQUIRED)
	add_subdirectory(util/doctest)
endif()

find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

add_library(stacksolvelib)
target_compile_features(stacksolvelib PUBLIC cxx_std_20) # 20: std::set::emplace()
target_include_directories(stacksolvelib PUBLIC src)
target_link_libraries(stacksolvelib PUBLIC fmt::fmt spdlog::spdlog)
target_sources(stacksolvelib
	PRIVATE
		src/executor.cpp
		src/i_node.cpp
		src/Board.cpp)

add_executable(stacksolve)
target_link_libraries(stacksolve PRIVATE stacksolvelib)
target_sources(stacksolve PRIVATE src/main.cpp)

add_executable(test_stacksolver)
target_link_libraries(test_stacksolver PRIVATE test_main stacksolvelib)
target_sources(test_stacksolver
	PRIVATE
		test/src/Board.cpp
		test/src/stacksolve/stack_state.cpp)

add_test(NAME stacksolver_test COMMAND test_stacksolver)

