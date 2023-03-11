// License: The Unlicense (https://unlicense.org)
#include "ttt/board.hpp"

#include "ttt/player.hpp"

#include <doctest/doctest.h>

TEST_CASE("encode/decode") {
  uint16_t board_value = 4;
  auto my_b = ttt::board::decode(ttt::player::EX, board_value);
  auto encoded_board = my_b.encode(ttt::player::EX);
  CHECK_EQ(board_value, encoded_board);
}

TEST_CASE("apply move") {
  auto board_a = ttt::board::decode(ttt::player::EX, 0);
  ttt::move mov(2,2,ttt::player::EX);
  auto board_b = board_a.apply(mov);
  auto b_value = board_b.encode(ttt::player::EX);
  CHECK_EQ(b_value, 1);
  b_value = board_b.encode(ttt::player::OH);
  CHECK_EQ(b_value, 2);
}
