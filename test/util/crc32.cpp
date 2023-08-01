#include "util/crc32.hpp"

#include <doctest/doctest.h>

TEST_CASE("Empty CRC") { CHECK(0U == tybl::util::crc32::get_crc(nullptr, 0)); }

TEST_CASE("Empty CRC") {
  static const int len = 8;
  uint8_t arr[len] = {0, 1, 2, 3, 4, 5, 6, 7};
  CHECK(2292869279U == tybl::util::crc32::get_crc(arr, len));
}
