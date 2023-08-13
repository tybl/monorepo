// License: The License (https://unlicense.org)
#pragma once
#ifndef PNT_NMEA_TALKERID_HPP
#define PNT_NMEA_TALKERID_HPP

namespace pnt::nmea {

enum class TalkerId {
  Unknown,
  GA,
  Galileo = GA,
  GB,
  BeiDou = GB,
  GI,
  NavIC = GI,
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
