// License: The License (https://unlicense.org)
#pragma once
#ifndef PNT_NMEA_SENTENCE_HPP
#define PNT_NMEA_SENTENCE_HPP

#include "SentenceType.hpp"
#include "TalkerId.hpp"

#include <cstdint>

namespace pnt::nmea {

struct Sentence {
  TalkerId talker_id;
  SentenceType sentence_type;
  uint8_t hour;
  uint8_t minute;
  float second;
};

} // namespace pnt::nmea

#endif // PNT_NMEA_SENTENCE_HPP
