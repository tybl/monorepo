// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_STATS_DISTRIBUTION_HPP
#define TYBL_STATS_DISTRIBUTION_HPP

#include <algorithm>
#include <cmath>
#include <limits>

namespace tybl::stats {

template <typename Type>
class distribution {
  std::size_t m_count{0UL};
  double m_mean{0.0};
  double m_sum_of_squares{0.0};
  Type m_maximum{std::numeric_limits<Type>::lowest()};
  Type m_minimum{std::numeric_limits<Type>::max()};

public:
  // TODO(tybl): Unintuitive use of operator+=, replace with regular function
  constexpr auto operator+=(Type p_x) -> distribution& {
    m_count += 1;
    double const delta = static_cast<double>(p_x) - m_mean;
    m_mean += delta / static_cast<double>(m_count);
    m_sum_of_squares += delta * (static_cast<double>(p_x) - m_mean);
    m_maximum = std::max(p_x, m_maximum);
    m_minimum = std::min(p_x, m_minimum);
    return *this;
  }

  [[nodiscard]] constexpr auto count() const -> std::size_t { return m_count; }

  [[nodiscard]] constexpr auto maximum() const -> Type { return m_maximum; }

  [[nodiscard]] constexpr auto minimum() const -> Type { return m_minimum; }

  [[nodiscard]] constexpr auto mean() const -> double { return m_mean; }

  [[nodiscard]] auto pop_stddev() const -> double { return std::sqrt(pop_var()); }

  [[nodiscard]] auto samp_stddev() const -> double { return std::sqrt(samp_var()); }

  [[nodiscard]] auto pop_var() const -> double {
    return (0 < m_count) ? (m_sum_of_squares / static_cast<double>(m_count)) : std::numeric_limits<double>::quiet_NaN();
  }

  [[nodiscard]] auto samp_var() const -> double {
    return (1 < m_count) ? (m_sum_of_squares / static_cast<double>(m_count - 1))
                         : std::numeric_limits<double>::quiet_NaN();
  }

}; // class distribution

} // namespace tybl::stats

#endif // TYBL_STATS_DISTRIBUTION_HPP