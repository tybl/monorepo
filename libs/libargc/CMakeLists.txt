################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################

find_package(fmt REQUIRED)

add_library(argcplusplus)
target_compile_features(argcplusplus PUBLIC cxx_std_20)
target_include_directories(argcplusplus PUBLIC include)
target_link_libraries(argcplusplus PUBLIC fmt::fmt)
target_sources(argcplusplus
	PRIVATE
		src/argc++/Application.cpp
		src/argc++/Argument.cpp
	PUBLIC
		include/argc++/Application.hpp
		include/argc++/Argument.hpp)

add_executable(test_argcplusplus)
target_link_libraries(test_argcplusplus PRIVATE argcplusplus test_main)
target_sources(test_argcplusplus
	PRIVATE
		test/argc++/test_help.cpp
		test/argc++/test_version.cpp)
add_test(NAME argcplusplus_test COMMAND test_argcplusplus)
