// License: The License (https://unlicense.org)
#pragma once
#ifndef PNT_NMEA_PARSE_HPP
#define PNT_NMEA_PARSE_HPP

#include "Sentence.hpp"

#include <memory>
#include <string_view>

namespace pnt::nmea {

auto parse(std::string_view p_input) -> std::unique_ptr<Sentence>;

} // namespace pnt::nmea

#endif // PNT_NMEA_PARSE_HPP
