// License: The Unlicense (https://unlicense.org)
#include "ttt/get_best_move.hpp"

#include <doctest/doctest.h>

// O X X
// X 0 0
// X E E

TEST_CASE("get_minimax_value()") {
  ttt::board brd;
  brd = brd.apply({0, 0, ttt::cell::value::OH});
  brd = brd.apply({0, 1, ttt::cell::value::EX});
  brd = brd.apply({0, 2, ttt::cell::value::EX});
  brd = brd.apply({1, 0, ttt::cell::value::EX});
  brd = brd.apply({1, 1, ttt::cell::value::OH});
  brd = brd.apply({1, 2, ttt::cell::value::OH});
  brd = brd.apply({2, 0, ttt::cell::value::EX});
  auto result = ttt::get_minimax_value(brd, {2, 1, ttt::cell::value::OH}, true);
  CHECK_EQ(0.0, result);
  result = ttt::get_minimax_value(brd, {2, 2, ttt::cell::value::OH}, true);
  CHECK_EQ(1.0, result);
}

TEST_CASE("get_best_move() between two simple options") {
  ttt::board brd;
  brd = brd.apply({0, 0, ttt::cell::value::OH});
  brd = brd.apply({0, 1, ttt::cell::value::EX});
  brd = brd.apply({0, 2, ttt::cell::value::EX});
  brd = brd.apply({1, 0, ttt::cell::value::EX});
  brd = brd.apply({1, 1, ttt::cell::value::OH});
  brd = brd.apply({1, 2, ttt::cell::value::OH});
  brd = brd.apply({2, 0, ttt::cell::value::EX});
  auto best_move = ttt::get_best_move(brd, ttt::cell::value::OH);
  REQUIRE(best_move.has_value());
  CHECK_EQ(best_move->row(), 2);
  CHECK_EQ(best_move->col(), 2);
}
