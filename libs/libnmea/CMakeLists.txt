# License: The Unlicense (https://unlicense.org)

add_executable(test_libnmea)
target_link_libraries(test_libnmea PRIVATE test_base)
target_sources(test_libnmea
  PRIVATE
    test/nmea/nmea.cpp
)

add_test(NAME libnmea_test COMMAND test_libnmea)