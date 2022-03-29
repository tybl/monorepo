// License: The License (https://unlicense.org)
#pragma once
#ifndef PNT_NMEA_SENTENCE_HPP
#define PNT_NMEA_SENTENCE_HPP

#include "SentenceType.hpp"
#include "TalkerId.hpp"

namespace pnt::nmea {

struct Sentence {
  TalkerId talker_id;
  SentenceType sentence_type;
};

} // namespace pnt::nmea

#endif // PNT_NMEA_SENTENCE_HPP
