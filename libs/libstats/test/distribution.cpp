// License: The Unlicense (https://unlicense.org)
#include "stats/distribution.hpp"

#include <doctest/doctest.h>

#include <array>
#include <iomanip>
#include <iostream>
#include <random>


TEST_CASE("cent example") {
  tybl::stats::distribution<int> dist;
  auto input = {5, 5, 10, 10, 10};
  for (auto i : input) {
    dist += i;
  }
  CHECK(8 == dist.mean());
}

TEST_CASE("weight example") {
  tybl::stats::distribution<double> dist;
  auto input = {79.8, 80.0, 80.1, 79.8, 80.2};
  for (auto i : input) {
    dist += i;
  }
  CHECK(79.98 == dist.mean());
}

TEST_CASE("team height") {
  tybl::stats::distribution<double> team_a_dist;
  tybl::stats::distribution<double> team_b_dist;
  std::array<double, 5> team_a = {1.89, 2.1, 1.75, 1.98, 1.85};
  std::array<double, 5> team_b = {1.94, 1.9, 1.97, 1.89, 1.87};
  for (int i = 0; i < 5; ++i) {
    team_a_dist += team_a[i];
    team_b_dist += team_b[i];
  }
  CHECK(1.914 == team_a_dist.mean());
  CHECK(1.914 == team_b_dist.mean());
  CHECK(doctest::Approx(0.014104) == team_a_dist.pop_var());
  CHECK(doctest::Approx(0.001304) == team_b_dist.pop_var());
}

