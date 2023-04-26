// License: The Unlicense (https://unlicense.org)
#include "tttai/get_best_move.hpp"

#include <doctest/doctest.h>

// X X 0
// X 0 0
// X E E
TEST_CASE("Game over") {
  ttt::board brd;
  brd = brd.apply({0, 0, ttt::cell::value::EX});
  brd = brd.apply({1, 1, ttt::cell::value::OH});
  brd = brd.apply({0, 1, ttt::cell::value::EX});
  brd = brd.apply({0, 2, ttt::cell::value::OH});
  brd = brd.apply({1, 0, ttt::cell::value::EX});
  brd = brd.apply({1, 2, ttt::cell::value::OH});
  brd = brd.apply({2, 0, ttt::cell::value::EX});
  auto best_move = tttai::get_best_move(brd);
  CHECK(!best_move.has_value());
}

// X O X
// O 0 X
// X X O
TEST_CASE("No moves available") {
  ttt::board brd;
  brd = brd.apply({0, 0, ttt::cell::value::EX});
  brd = brd.apply({1, 1, ttt::cell::value::OH});
  brd = brd.apply({0, 2, ttt::cell::value::EX});
  brd = brd.apply({0, 1, ttt::cell::value::OH});
  brd = brd.apply({2, 1, ttt::cell::value::EX});
  brd = brd.apply({1, 0, ttt::cell::value::OH});
  brd = brd.apply({1, 2, ttt::cell::value::EX});
  brd = brd.apply({2, 2, ttt::cell::value::OH});
  brd = brd.apply({2, 0, ttt::cell::value::EX});
  auto best_move = tttai::get_best_move(brd);
  CHECK(!best_move.has_value());
}

TEST_CASE("0|X|X  X|O|O  X|#|#") {
  ttt::board brd;
  brd = brd.apply({0, 1, ttt::cell::value::EX});
  brd = brd.apply({0, 0, ttt::cell::value::OH});
  brd = brd.apply({0, 2, ttt::cell::value::EX});
  brd = brd.apply({1, 1, ttt::cell::value::OH});
  brd = brd.apply({1, 0, ttt::cell::value::EX});
  brd = brd.apply({1, 2, ttt::cell::value::OH});
  brd = brd.apply({2, 0, ttt::cell::value::EX});
  auto best_move = tttai::get_best_move(brd);
  REQUIRE(best_move.has_value());
  CHECK_EQ(best_move->row(), 2);
  CHECK_EQ(best_move->col(), 2);
}

TEST_CASE("#|X|#  #|#|X  O|O|X") {
  ttt::board brd;
  brd = brd.apply({0, 1, ttt::cell::value::EX});
  brd = brd.apply({2, 0, ttt::cell::value::OH});
  brd = brd.apply({1, 2, ttt::cell::value::EX});
  brd = brd.apply({2, 1, ttt::cell::value::OH});
  brd = brd.apply({2, 2, ttt::cell::value::EX});
  auto best_move = tttai::get_best_move(brd);
  REQUIRE(best_move.has_value());
  CHECK_EQ(best_move->row(), 0);
  CHECK_EQ(best_move->col(), 2);
}

TEST_CASE("O|X|#  #|#|X  O|O|X") {
  ttt::board brd;
  brd = brd.apply({0, 1, ttt::cell::value::EX});
  brd = brd.apply({2, 0, ttt::cell::value::OH});
  brd = brd.apply({1, 2, ttt::cell::value::EX});
  brd = brd.apply({2, 1, ttt::cell::value::OH});
  brd = brd.apply({2, 2, ttt::cell::value::EX});
  brd = brd.apply({0, 0, ttt::cell::value::OH});
  auto best_move = tttai::get_best_move(brd);
  REQUIRE(best_move.has_value());
  CHECK_EQ(best_move->row(), 0);
  CHECK_EQ(best_move->col(), 2);
}

TEST_CASE("O|X|O  X|#|X  O|O|X") {
  ttt::board brd;
  brd = brd.apply({0, 1, ttt::cell::value::EX});
  brd = brd.apply({2, 0, ttt::cell::value::OH});
  brd = brd.apply({1, 2, ttt::cell::value::EX});
  brd = brd.apply({2, 1, ttt::cell::value::OH});
  brd = brd.apply({2, 2, ttt::cell::value::EX});
  brd = brd.apply({0, 0, ttt::cell::value::OH});
  brd = brd.apply({1, 0, ttt::cell::value::EX});
  brd = brd.apply({0, 2, ttt::cell::value::OH});
  auto best_move = tttai::get_best_move(brd);
  REQUIRE(best_move.has_value());
  CHECK_EQ(best_move->row(), 1);
  CHECK_EQ(best_move->col(), 1);
}

TEST_CASE("#|X|O  #|#|X  O|O|X") {
  ttt::board brd;
  brd = brd.apply({0, 1, ttt::cell::value::EX});
  brd = brd.apply({2, 0, ttt::cell::value::OH});
  brd = brd.apply({1, 2, ttt::cell::value::EX});
  brd = brd.apply({2, 1, ttt::cell::value::OH});
  brd = brd.apply({2, 2, ttt::cell::value::EX});
  brd = brd.apply({0, 2, ttt::cell::value::OH});
  auto best_move = tttai::get_best_move(brd);
  REQUIRE(best_move.has_value());
  CHECK_EQ(best_move->row(), 1);
  CHECK_EQ(best_move->col(), 1);
}

TEST_CASE("#|#|#  #|#|#  #|#|#") {
  ttt::board brd;
  auto best_move = tttai::get_best_move(brd);
  REQUIRE(best_move.has_value());
  CHECK_EQ(best_move->row(), 0);
  CHECK_EQ(best_move->col(), 0);
}

TEST_CASE("X|#|#  #|#|#  #|#|#") {
  ttt::board brd;
  brd = brd.apply({0, 0, ttt::cell::value::EX});
  auto best_move = tttai::get_best_move(brd);
  REQUIRE(best_move.has_value());
  CHECK_EQ(best_move->row(), 1);
  CHECK_EQ(best_move->col(), 1);
}

TEST_CASE("X|#|#  #|O|#  #|#|#") {
  ttt::board brd;
  brd = brd.apply({0, 0, ttt::cell::value::EX});
  brd = brd.apply({1, 1, ttt::cell::value::OH});
  auto best_move = tttai::get_best_move(brd);
  REQUIRE(best_move.has_value());
  CHECK_EQ(best_move->row(), 0);
  CHECK_EQ(best_move->col(), 1); // This one is strange to me.
}

TEST_CASE("X|X|#  #|O|#  #|#|#") {
  ttt::board brd;
  brd = brd.apply({0, 0, ttt::cell::value::EX});
  brd = brd.apply({1, 1, ttt::cell::value::OH});
  brd = brd.apply({0, 1, ttt::cell::value::EX});
  auto best_move = tttai::get_best_move(brd);
  REQUIRE(best_move.has_value());
  CHECK_EQ(best_move->row(), 0);
  CHECK_EQ(best_move->col(), 2);
}

TEST_CASE("X|X|O  #|O|#  #|#|#") {
  ttt::board brd;
  brd = brd.apply({0, 0, ttt::cell::value::EX});
  brd = brd.apply({1, 1, ttt::cell::value::OH});
  brd = brd.apply({0, 1, ttt::cell::value::EX});
  brd = brd.apply({0, 2, ttt::cell::value::OH});
  auto best_move = tttai::get_best_move(brd);
  REQUIRE(best_move.has_value());
  CHECK_EQ(best_move->row(), 2);
  CHECK_EQ(best_move->col(), 0);
}

TEST_CASE("X|X|O  #|O|#  X|#|#") {
  ttt::board brd;
  brd = brd.apply({0, 0, ttt::cell::value::EX});
  brd = brd.apply({1, 1, ttt::cell::value::OH});
  brd = brd.apply({0, 1, ttt::cell::value::EX});
  brd = brd.apply({0, 2, ttt::cell::value::OH});
  brd = brd.apply({2, 0, ttt::cell::value::EX});
  auto best_move = tttai::get_best_move(brd);
  REQUIRE(best_move.has_value());
  CHECK_EQ(best_move->row(), 1);
  CHECK_EQ(best_move->col(), 0);
}
