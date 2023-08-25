// License: The License (https://unlicense.org)
#include <nmea/parse.hpp>

#include <cassert>
#include <charconv>
#include <cmath>

namespace pnt::nmea {

enum class Hour : uint8_t {};
enum class Minute : uint8_t {};

struct TimeOfDay {
  static auto parse(std::string_view& p_input) {
    TimeOfDay result{};
    auto fcr = std::from_chars(p_input.begin(), p_input.end(), result.m_value);
    auto delta = fcr.ptr - p_input.begin();
    p_input = p_input.substr(delta);
    return result;
  }
  auto hour() const { return static_cast<Hour>(m_value / 10000); }
  auto minute() const { return static_cast<Minute>(std::fmod(m_value, 10000.0F) / 100); }
  auto second() const { return std::fmod(m_value, 100.0F); }

private:
  float m_value;
};

auto parse(std::string_view p_input) -> std::unique_ptr<Sentence> {
  using namespace std::literals;
  if (!p_input.starts_with("$G"sv) || !p_input.ends_with("\r\n"sv)) {
    return nullptr;
  }
  auto result = std::make_unique<Sentence>();
  switch (p_input[2]) {
    case 'A': result->talker_id = TalkerId::GA; break;
    case 'B': result->talker_id = TalkerId::GB; break;
    case 'I': result->talker_id = TalkerId::GI; break;
    case 'L': result->talker_id = TalkerId::GL; break;
    case 'N': result->talker_id = TalkerId::GN; break;
    case 'P': result->talker_id = TalkerId::GP; break;
    case 'Q': result->talker_id = TalkerId::GQ; break;
    default: result->talker_id = TalkerId::Unknown; break;
  }
  p_input = p_input.substr(3);
  if (p_input.starts_with("GGA"sv)) {
    result->sentence_type = SentenceType::GGA;
  } else if (p_input.starts_with("GSA"sv)) {
    result->sentence_type = SentenceType::GSA;
  } else if (p_input.starts_with("GSV"sv)) {
    result->sentence_type = SentenceType::GSV;
  } else if (p_input.starts_with("RMC"sv)) {
    result->sentence_type = SentenceType::RMC;
  } else if (p_input.starts_with("VTG"sv)) {
    result->sentence_type = SentenceType::VTG;
  }
  assert(',' == p_input.at(3));
  p_input = p_input.substr(4);
  auto tod = TimeOfDay::parse(p_input);
  result->hour = static_cast<uint8_t>(tod.hour());
  result->minute = static_cast<uint8_t>(tod.minute());
  result->second = tod.second();
  return result;
}

} // namespace pnt::nmea