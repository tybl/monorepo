// License: The License (https://unlicense.org)
#include <nmea/parse.hpp>

namespace pnt::nmea {

auto parse(std::string_view p_input) -> std::unique_ptr<Sentence> {
  using namespace std::literals;
  if (!p_input.starts_with("$G"sv) || !p_input.ends_with("\r\n"sv)) {
    return nullptr;
  }
  auto result = std::make_unique<Sentence>();
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
  return result;
}

} // namespace pnt::nmea