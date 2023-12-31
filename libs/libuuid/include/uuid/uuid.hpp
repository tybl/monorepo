// License: The Unlicense (https://unlicense.org)
#pragma once

#include <compare>
#include <string>

namespace vodka::util {

class uuid {
  std::string mValue;

public:
  uuid();

  static auto Create() -> uuid;

  [[nodiscard]] auto operator<=>(uuid const&) const = default;

  [[nodiscard, gnu::const]] auto to_string() const -> std::string const&;

private:
  static constexpr auto const uuid_file = "/proc/sys/kernel/random/uuid";

  static constexpr auto const nil = "00000000-0000-0000-0000-000000000000";

  explicit uuid(std::string value);

  static auto GenerateStr() -> std::string;

}; // struct Uuid

} // namespace vodka::util
