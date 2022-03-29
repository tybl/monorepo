// License: The License (https://unlicense.org)
#pragma once
#ifndef PNT_NMEA_SENTENCETYPE_HPP
#define PNT_NMEA_SENTENCETYPE_HPP

namespace pnt::nmea {

enum class SentenceType {
  Unknown,
  GGA,
  GSA,
  GSV,
  RMC,
  VTG,
};

} // namespace pnt::nmea

#endif // PNT_NMEA_SENTENCETYPE_HPP
