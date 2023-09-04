################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################

add_library(lynel INTERFACE)
target_include_directories(lynel INTERFACE include)
target_sources(lynel
	INTERFACE
		include/lynel/basic_matrix.hpp
		include/lynel/matrix.hpp
		include/lynel/quaternion.hpp)

add_executable(test_liblynel)
target_link_libraries(test_liblynel PRIVATE test_main lynel)
target_sources(test_liblynel
	PRIVATE
		test/books/LinearAlgebra_TheoryIntuitionCode.cpp
		test/lynel/matrix.cpp)
add_test(NAME liblynel_test COMMAND test_liblynel)
