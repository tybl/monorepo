// License: The Unlicense (https://unlicense.org)
#include <nmea/parse.hpp>

#include <doctest/doctest.h>

TEST_CASE("Is a nmea sentence") {
  using namespace std::literals;
  auto result = pnt::nmea::parse("$GCGSV,\r\n"sv);
  CHECK(result);
  CHECK(pnt::nmea::TalkerId::Unknown == result->talker_id);
}

TEST_CASE("Isn't a nmea sentence") {
  using namespace std::literals;
  auto result = pnt::nmea::parse("$GNGSA,\n\n"sv);
  CHECK(!result);
}

TEST_CASE("TalkerIds") {
  using namespace std::literals;
  auto result = pnt::nmea::parse("$GAVTG,\r\n"sv);
  REQUIRE(result);
  CHECK(pnt::nmea::TalkerId::Galileo == result->talker_id);
  result = pnt::nmea::parse("$GBRMC,\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::TalkerId::BeiDou == result->talker_id);
  result = pnt::nmea::parse("$GIRMC,\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::TalkerId::NavIC == result->talker_id);
  result = pnt::nmea::parse("$GLRMC,\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::TalkerId::GLONASS == result->talker_id);
  result = pnt::nmea::parse("$GNRMC,\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::TalkerId::GNSS == result->talker_id);
  result = pnt::nmea::parse("$GPRMC,\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::TalkerId::GPS == result->talker_id);
  result = pnt::nmea::parse("$GQRMC,\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::TalkerId::QZSS == result->talker_id);
}

TEST_CASE("SentenceTypes") {
  using namespace std::literals;
  auto result = pnt::nmea::parse("$GPRGB,\r\n"sv);
  REQUIRE(result);
  CHECK(pnt::nmea::SentenceType::Unknown == result->sentence_type);
  result = pnt::nmea::parse("$GPGGA,\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::SentenceType::GGA == result->sentence_type);
  result = pnt::nmea::parse("$GPGSA,\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::SentenceType::GSA == result->sentence_type);
  result = pnt::nmea::parse("$GPGSV,\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::SentenceType::GSV == result->sentence_type);
  result = pnt::nmea::parse("$GPRMC,\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::SentenceType::RMC == result->sentence_type);
  result = pnt::nmea::parse("$GPVTG,\r\n");
  REQUIRE(result);
  CHECK(pnt::nmea::SentenceType::VTG == result->sentence_type);
}

TEST_CASE("GGA Time of day") {
  using namespace std::literals;
  auto result = pnt::nmea::parse("$GPGGA,123456.789\r\n"sv);
  REQUIRE(result);
  CHECK(12 == result->hour);
  CHECK(34 == result->minute);
  CHECK(doctest::Approx(56.789) == result->second);
  result = pnt::nmea::parse("$GPGGA,212022.000\r\n"sv);
  REQUIRE(result);
  CHECK(21 == result->hour);
  CHECK(20 == result->minute);
  CHECK(doctest::Approx(22.00) == result->second);
}