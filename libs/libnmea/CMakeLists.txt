# License: The Unlicense (https://unlicense.org)

add_library(libnmea)
target_include_directories(libnmea PUBLIC include)
target_sources(libnmea PRIVATE src/nmea/parse.cpp)

add_executable(test_libnmea)
target_link_libraries(test_libnmea PRIVATE libnmea test_base)
target_sources(test_libnmea PRIVATE test/nmea/parse.cpp)

add_test(NAME libnmea_test COMMAND test_libnmea)
