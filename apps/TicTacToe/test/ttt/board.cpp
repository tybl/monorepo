// License: The Unlicense (https://unlicense.org)
#include "ttt/board.hpp"

#include "ttt/bad_move.hpp"
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
  const ttt::move mov(2, 2, ttt::cell::value::EX);
  auto board_b = board_a.apply(mov);
  auto b_value = board_b.encode(ttt::cell::value::EX);
  CHECK_EQ(b_value, 1);
  b_value = board_b.encode(ttt::cell::value::OH);
  CHECK_EQ(b_value, 2);
}

TEST_CASE("#1: Prevent multiple moves targeting the same cell") {
  ttt::board brd;
  brd = brd.apply({0,0,static_cast<ttt::cell::value>('X')});
  CHECK_THROWS_AS(brd.apply({0,0,static_cast<ttt::cell::value>('O')}), ttt::bad_move);
}

TEST_CASE("Confirm next move") {
  ttt::board brd;
  brd = brd.apply({0,0,ttt::cell::value::EX});
  CHECK(ttt::cell::value::OH == brd.get_next_turn());
  brd = brd.apply({0,1,ttt::cell::value::OH});
  CHECK(ttt::cell::value::EX == brd.get_next_turn());
}

TEST_CASE("Require alternating turns") {
  ttt::board brd;
  brd = brd.apply({0,0,ttt::cell::value::EX});
  CHECK_THROWS_AS(brd.apply({0,1,ttt::cell::value::EX}), ttt::bad_move);
}

TEST_CASE("Graphviz integration") {
  ttt::board brd;
  auto dot_str = brd.to_dot_string();
  CHECK_EQ(dot_str, "Empty [fontname=\"mono\" fontcolor=\"black\" shape=none label=\"___\\n___\\n___\"];");
  brd = brd.apply({2,1,ttt::cell::value::EX});
  dot_str = brd.to_dot_string();
  CHECK_EQ(dot_str, "m7 [fontname=\"mono\" fontcolor=\"black\" shape=none label=\"___\\n___\\n_X_\"];");
  brd = brd.apply({0,0,ttt::cell::value::OH});
  dot_str = brd.to_dot_string();
  CHECK_EQ(dot_str, "m70 [fontname=\"mono\" fontcolor=\"black\" shape=none label=\"O__\\n___\\n_X_\"];");
}
