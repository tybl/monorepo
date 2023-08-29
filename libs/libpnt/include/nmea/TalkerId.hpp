// License: The License (https://unlicense.org)
#pragma once
#ifndef PNT_NMEA_TALKERID_HPP
#define PNT_NMEA_TALKERID_HPP

namespace pnt::nmea {

enum class TalkerId {
  UNKNOWN,
  GA,
  GALILEO = GA,
  GB,
  BEI_DOU = GB,
  GI,
  NAV_IC = GI,
  GL,
  GLONASS = GL,
  GN,
  GNSS = GN,
  GP,
  GPS = GP,
  GQ,
  QZSS = GQ,
};

} // namespace pnt::nmea

#endif // PNT_NMEA_TALKERID_HPP
