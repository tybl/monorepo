// License: The Unlicense (https://unlicense.org)
#include "stats/distribution.hpp"

#include <doctest/doctest.h>

#include <array>
#include <iomanip>
#include <iostream>
#include <random>

TEST_CASE("cent example") {
  tybl::stats::distribution<int> dist;
  auto input = {5, 5, 10, 10, 10}; // NOLINT(*-magic-numbers)
  for (auto sample : input) {
    dist += sample;
  }
  CHECK(8 == dist.mean());
}

TEST_CASE("weight example") {
  tybl::stats::distribution<double> dist;
  auto input = {79.8, 80.0, 80.1, 79.8, 80.2}; // NOLINT(*-magic-numbers)
  for (auto sample : input) {
    dist += sample;
  }
  CHECK(79.98 == dist.mean()); // NOLINT(*-magic-numbers)
}

TEST_CASE("team height") {
  tybl::stats::distribution<double> team_a_dist;
  tybl::stats::distribution<double> team_b_dist;
  static constexpr size_t LEN = 5;
  std::array<double, LEN> team_a = {1.89, 2.1, 1.75, 1.98, 1.85}; // NOLINT(*-magic-numbers)
  std::array<double, LEN> team_b = {1.94, 1.9, 1.97, 1.89, 1.87}; // NOLINT(*-magic-numbers)
  for (size_t i = 0; i < LEN; ++i) {
    team_a_dist += team_a.at(i);
    team_b_dist += team_b.at(i);
  }
  CHECK(1.914 == team_a_dist.mean());                        // NOLINT(*-magic-numbers)
  CHECK(1.914 == team_b_dist.mean());                        // NOLINT(*-magic-numbers)
  CHECK(doctest::Approx(0.014104) == team_a_dist.pop_var()); // NOLINT(*-magic-numbers)
  CHECK(doctest::Approx(0.001304) == team_b_dist.pop_var()); // NOLINT(*-magic-numbers)
}
