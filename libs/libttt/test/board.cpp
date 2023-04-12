// License: The Unlicense (https://unlicense.org)
#include "ttt/board.hpp"

#include "ttt/cell.hpp"

#include <doctest/doctest.h>

TEST_CASE("encode/decode") {
  const uint16_t board_value = 4;
  auto my_b = ttt::board::decode(ttt::cell::value::EX, board_value);
  auto encoded_board = my_b.encode(ttt::cell::value::EX);
  CHECK_EQ(board_value, encoded_board);
}

TEST_CASE("apply move") {
  auto board_a = ttt::board::decode(ttt::cell::value::EX, 0);
  const ttt::move mov(2,2,ttt::cell::value::EX);
  auto board_b = board_a.apply(mov);
  auto b_value = board_b.encode(ttt::cell::value::EX);
  CHECK_EQ(b_value, 1);
  b_value = board_b.encode(ttt::cell::value::OH);
  CHECK_EQ(b_value, 2);
}
