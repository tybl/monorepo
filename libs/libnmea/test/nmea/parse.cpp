// License: The Unlicense (https://unlicense.org)
#include <nmea/parse.hpp>

#include <doctest/doctest.h>

TEST_CASE("Is a nmea sentence") {
  auto result = pnt::nmea::parse("$G\r\n");
  CHECK(result);
  CHECK(pnt::nmea::TalkerId::Unknown == result->talker_id);
}

TEST_CASE("Isn't a nmea sentence") {
  auto result = pnt::nmea::parse("$G\n\n");
  CHECK(!result);
}

TEST_CASE("TalkerIds") {
  auto result = pnt::nmea::parse("$GA\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::TalkerId::Galileo == result->talker_id);
  result = pnt::nmea::parse("$GB\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::TalkerId::BeiDou == result->talker_id);
  result = pnt::nmea::parse("$GI\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::TalkerId::NavIC == result->talker_id);
  result = pnt::nmea::parse("$GL\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::TalkerId::GLONASS == result->talker_id);
  result = pnt::nmea::parse("$GN\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::TalkerId::GNSS == result->talker_id);
  result = pnt::nmea::parse("$GP\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::TalkerId::GPS == result->talker_id);
  result = pnt::nmea::parse("$GQ\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::TalkerId::QZSS == result->talker_id);
}

TEST_CASE("SentenceTypes") {
  auto result = pnt::nmea::parse("$GA\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::SentenceType::Unknown == result->sentence_type);
  result = pnt::nmea::parse("$GPGGA\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::SentenceType::GGA == result->sentence_type);
  result = pnt::nmea::parse("$GPGSA\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::SentenceType::GSA == result->sentence_type);
  result = pnt::nmea::parse("$GPGSV\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::SentenceType::GSV == result->sentence_type);
  result = pnt::nmea::parse("$GPRMC\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::SentenceType::RMC == result->sentence_type);
  result = pnt::nmea::parse("$GPVTG\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::SentenceType::VTG == result->sentence_type);
}
