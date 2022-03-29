// License: The Unlicense (https://unlicense.org)

#include <doctest/doctest.h>

#include <iostream>
#include <memory>
#include <string_view>

namespace pnt {

struct nmea {

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

  static auto parse(std::string_view p_input) -> std::unique_ptr<nmea>;

  TalkerId talker_id;
};

} // namespace pnt

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

namespace pnt {

auto nmea::parse(std::string_view p_input) -> std::unique_ptr<nmea> {
  using namespace std::literals;
  if (!p_input.starts_with("$G"sv) || !p_input.ends_with("\r\n"sv)) {
    return nullptr;
  }
  auto result = std::make_unique<nmea>();
  switch(p_input[2]) {
    case 'A':
      result->talker_id = TalkerId::GA; break;
    case 'B':
      result->talker_id = TalkerId::GB; break;
    case 'I':
      result->talker_id = TalkerId::GI; break;
    case 'L':
      result->talker_id = TalkerId::GL; break;
    case 'N':
      result->talker_id = TalkerId::GN; break;
    case 'P':
      result->talker_id = TalkerId::GP; break;
    case 'Q':
      result->talker_id = TalkerId::GQ; break;
    default:
      result->talker_id = TalkerId::Unknown; break;
  }
  return result;
}

} // namespace pnt