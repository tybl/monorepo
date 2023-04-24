// License: The Unlicense (https://unlicense.org)
#include "ttt/cell.hpp"

#include "ttt/bad_move.hpp"

#include <doctest/doctest.h>

TEST_CASE("Limit the range of ttt::cell::position's row and columns") {
  CHECK_NOTHROW(ttt::cell::position(0,0));
  CHECK_NOTHROW(ttt::cell::position(0,1));
  CHECK_NOTHROW(ttt::cell::position(0,2));
  CHECK_NOTHROW(ttt::cell::position(1,0));
  CHECK_NOTHROW(ttt::cell::position(1,1));
  CHECK_NOTHROW(ttt::cell::position(1,2));
  CHECK_NOTHROW(ttt::cell::position(2,0));
  CHECK_NOTHROW(ttt::cell::position(2,1));
  CHECK_NOTHROW(ttt::cell::position(2,2));
  CHECK_THROWS_AS(ttt::cell::position(0,3), ttt::bad_move);
  CHECK_THROWS_AS(ttt::cell::position(3,0), ttt::bad_move);
  CHECK_THROWS_AS(ttt::cell::position(0,-1), ttt::bad_move);
  CHECK_THROWS_AS(ttt::cell::position(-1,0), ttt::bad_move);
}
