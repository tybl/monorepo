################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet:ts=2
################################################################################

add_library(util)
add_library(libutil::util ALIAS util)
target_include_directories(util PUBLIC include)
target_sources(util
	PRIVATE
		src/util/crc32.cpp
		src/util/get_config_path.cpp
		src/util/get_home_path.cpp
	PUBLIC
		include/util/crc32.hpp
		include/util/get_config_path.hpp
		include/util/get_home_path.hpp
		include/util/string_contains.hpp)

add_executable(test_libutil)
target_link_libraries(test_libutil PRIVATE test_main util)
target_sources(test_libutil
	PRIVATE
		test/util/crc32.cpp
		test/util/string_contains.cpp)
add_test(NAME libutil_test COMMAND test_libutil)
