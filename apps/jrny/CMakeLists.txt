################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:noet
################################################################################

find_package(tomlplusplus REQUIRED)

add_executable(jrny)
target_compile_features(jrny PRIVATE cxx_std_20) # std::span
target_link_libraries(jrny PRIVATE libutil::util tomlplusplus)
target_sources(jrny PRIVATE src/jrny.cpp)
