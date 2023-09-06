################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################

find_package(fmt REQUIRED)

add_executable(sbee)
target_compile_features(sbee PRIVATE cxx_std_20) # std::span
target_link_libraries(sbee PRIVATE fmt::fmt sbeelib)
target_link_options(sbee PRIVATE $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
target_sources(sbee PRIVATE src/sbee.cpp)

add_executable(stacks)
target_link_libraries(stacks PRIVATE stacksolvelib)
target_link_options(stacks PRIVATE $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
target_sources(stacks PRIVATE src/stacks.cpp)

add_executable(tactic)
target_link_libraries(tactic PRIVATE ttt tttai)
target_link_options(tactic PRIVATE $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
target_sources(tactic
	PRIVATE
		src/tactic/game.cpp
		src/tactic/main.cpp)
