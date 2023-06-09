################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################

add_executable(prune)
target_link_libraries(prune
        PRIVATE
        compiler_settings
        fmt
	)
target_sources(prune
        PRIVATE
        src/main.cpp
        )


#add_executable(test_)
#target_link_libraries(test_search PRIVATE compiler_settings stats test_base ttt)
#target_sources(test_search
#        PRIVATE
#        src/search_moves.cpp)
#add_test(NAME search_test COMMAND test_search)

