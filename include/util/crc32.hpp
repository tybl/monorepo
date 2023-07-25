#pragma once

#include <cstddef>
#include <cstdint>

namespace tybl::util {

class crc32
{
   uint32_t m_crc;

   const static uint32_t CRC_32 = 0x04c11db7;
   const static uint32_t FLIP_MASK = 0xffffffff;
   const static uint32_t INITIAL_VALUE = 0xffffffff;

   crc32(void) : m_crc(INITIAL_VALUE) {};

   uint32_t finalize(void);

   uint32_t update(const uint8_t *data, size_t dataLen);

   uint32_t reflect(uint32_t data);

public:

   static uint32_t get_crc(const uint8_t* data, size_t dataLen);

   static uint32_t validate(const uint8_t* data, size_t dataLen, uint32_t crcValue);

};

} // namespace tybl::util

