// License: The Unlicense (https://unlicense.org)
#include "ttt/board.hpp"

#include "ttt/player.hpp"

#include <doctest/doctest.h>

TEST_CASE("encode/decode") {
  ttt::board my_b;
  uint16_t board_value = 4;
  my_b.decode(ttt::player::EX, board_value);
  auto encoded_board = my_b.encode(ttt::player::EX);
  CHECK_EQ(board_value, encoded_board);
}
