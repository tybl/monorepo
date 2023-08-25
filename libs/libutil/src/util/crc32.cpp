// License: The Unlicense (https://unlicense.org)
// vim:ts=2:sts=2:sw=2:et
#include "util/crc32.hpp"

namespace tybl::util {

uint32_t crc32::get_crc(uint8_t const* p_data, size_t p_data_length) {
  crc32 value;

  value.update(p_data, p_data_length);

  // Finalize the CRC for evaluation
  value.finalize();

  return value.m_crc;
}

uint32_t crc32::validate(uint8_t const* p_data, size_t p_data_length, uint32_t p_crc_value) {
  uint32_t value = get_crc(p_data, p_data_length);

  return (value == p_crc_value) ? 0 : value;
}

uint32_t crc32::reflect(uint32_t p_data) {
  unsigned int i;
  uint32_t ret = 0;
  bool lowest_bit = (p_data & 0x01);

  // Set the first (will be highest) bit of the return value to the lowest bit of data
  ret |= lowest_bit;

  // 32 can be assumed here, because we are specifically using a uint32_t (32-bit) field
  for (i = 1; i < 32; i++) {
    // Throw away the lowest bit of the data variable
    p_data >>= 1;

    // Get the lowest bit of data
    lowest_bit = (p_data & 0x01);

    // Push the return value to the left
    ret <<= 1;

    // Set the next bit of ret with the lowest bit of data
    ret |= lowest_bit;
  }
  return ret;
}

uint32_t crc32::finalize(void) {
  // The reflection and flip are standard
  m_crc = reflect(m_crc) ^ FLIP_MASK;
  return m_crc;
}

uint32_t crc32::update(const uint8_t* p_data, size_t p_data_length) {
  unsigned int i;
  bool bit;
  unsigned char c;

  while (p_data_length--) {
    // Get next data word
    c = *p_data++;

    // Cycle through each bit of the data word, lowest to highest (This is generally for little-endianness, as defined
    // by IEEE standard, but actual endianness doesn't matter so long as we're consistent)
    for (i = 0x01; i & 0xff; i <<= 1) {
      // Look at first bit of the current CRC value
      bit = ((m_crc & 0x80000000) != 0);

      // Look at only i-th bit of the current word
      if (c & i) {
        bit = !bit;
      }

      // This is done in every iteration. It moves with each new bit we compare against
      m_crc <<= 1;

      // Essentially: If(XOR of the ith bit of the word and the leading bit of the CRC == 1)
      if (bit) {
        m_crc ^= CRC_32;
      }
    }
  }
  return m_crc;
}

} // namespace tybl::util
