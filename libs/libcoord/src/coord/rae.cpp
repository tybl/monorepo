// License: The Unlicense (https://unlicense.org)
#include "coord/rae.hpp"

#include "coord/frd.hpp"

#include <cmath> // cos, sin

namespace tybl::coord {

rae_t::rae_t(double p_range, double p_azimuth, double p_elevation)
  : m_range(p_range)
  , m_azimuth(p_azimuth)
  , m_elevation(p_elevation) {}

auto rae_t::to_frd() const -> frd_t {
  auto const hypotenuse = std::cos(elevation()) * range();
  auto const front = std::sin(azimuth()) * hypotenuse;
  auto const right = std::cos(azimuth()) * hypotenuse;
  auto const down = std::sin(elevation()) * range();
  return {front, right, down};
}

auto rae_t::range() const -> double { return m_range; }

auto rae_t::azimuth() const -> double { return m_azimuth; }

auto rae_t::elevation() const -> double { return m_elevation; }

} // namespace tybl::coord
