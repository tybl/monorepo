################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################

find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

add_library(stacksolvelib)
target_compile_features(stacksolvelib PUBLIC cxx_std_20) # 20: std::set::emplace()
target_include_directories(stacksolvelib PUBLIC include)
target_link_libraries(stacksolvelib PUBLIC fmt::fmt spdlog::spdlog)
target_sources(stacksolvelib
	PRIVATE
		src/executor.cpp
		src/i_node.cpp
		src/board.cpp)

add_executable(test_stacksolver)
target_link_libraries(test_stacksolver PRIVATE test_main stacksolvelib)
target_sources(test_stacksolver
	PRIVATE
		test/board.cpp
		test/stack_state.cpp)
add_test(NAME stacksolver_test COMMAND test_stacksolver)
