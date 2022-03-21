// License: The Unlicense (https://unlicense.org)

#include <doctest/doctest.h>

#include <memory>
#include <string_view>

namespace pnt {

struct nmea {
  static auto parse(std::string_view input) -> std::unique_ptr<nmea>;
};

auto nmea::parse(std::string_view input) -> std::unique_ptr<nmea> {
  using namespace std::literals;
  if (!input.starts_with("$G"sv) || !input.ends_with("\r\n"sv)) {
    return nullptr;
  }
  return std::make_unique<nmea>();
}

} // namespace pnt

TEST_CASE("Is a nmea sentence") {
  auto result = pnt::nmea::parse("$G\r\n");
  CHECK(result);
}

TEST_CASE("Isn't a nmea sentence") {
  auto result = pnt::nmea::parse("$G\n\n");
  CHECK(!result);
}
