################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################

add_executable(jrny)
set_target_properties(jrny PROPERTIES
   CXX_STANDARD 20
   CXX_STANDARD_REQUIRED ON)
target_link_libraries(jrny PRIVATE tomlplusplus)
target_sources(jrny
        PRIVATE
        src/main.cpp
)
