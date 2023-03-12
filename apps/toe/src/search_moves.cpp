#include "ttt/board.hpp"
#include "stats/distribution.hpp"

#include <cstdarg>
#include <doctest/doctest.h>

#include <iostream>
#include <optional>

auto get_expected_value(ttt::board const& p_board, ttt::move p_move) -> float {
  auto curr_board = p_board.apply(p_move);
  if (curr_board.has_winner()) {
    return 1.0;
  }
  const ttt::cell::value player = (ttt::cell::value::EX == p_move.value()) ? ttt::cell::value::OH : ttt::cell::value::EX;
  tybl::stats::distribution<float> dist;
  for (uint16_t row = 0; row < 3; ++row) {
    for (uint16_t col = 0; col < 3; ++col) {
      const ttt::move next(row, col, player);
      if (curr_board.is_empty(next.pos())) {
        dist += get_expected_value(curr_board, next);
      }
    }
  }
  return static_cast<float>(1.0 - dist.mean());
}

auto get_minimax_value(ttt::board const& p_board, ttt::move p_move, bool p_do_maximize) -> float {
#if 0
  if (p_do_maximize) {
    std::cout << "get_*max*_value(\"" << static_cast<char>(p_move.value()) << "\" @ (" << p_move.pos().row() << ", " << p_move.pos().col() << ")\n";
  } else {
    std::cout << "get_*min*_value(\"" << static_cast<char>(p_move.value()) << "\" @ (" << p_move.pos().row() << ", " << p_move.pos().col() << ")\n";
  }
  p_board.display();
#endif
  auto curr_board = p_board.apply(p_move);
  if (curr_board.has_winner()) {
    return 1.0;
  }
  if (curr_board.is_tie()) {
    return 0.0;
  }
  const ttt::cell::value player = (ttt::cell::value::EX == p_move.value()) ? ttt::cell::value::OH : ttt::cell::value::EX;
  if (p_do_maximize) {
    float result = -1.0;
    for (uint16_t row = 0; row < 3; ++row) {
      for (uint16_t col = 0; col < 3; ++col) {
        const ttt::move next(row, col, player);
        if (curr_board.is_empty(next.pos())) {
          result = std::max(result, get_minimax_value(curr_board, next, !p_do_maximize));
        }
      }
    }
    return result;
  } 
  float result = 1.0;
  for (uint16_t row = 0; row < 3; ++row) {
    for (uint16_t col = 0; col < 3; ++col) {
      const ttt::move next(row, col, player);
      if (curr_board.is_empty(next.pos())) {
        result = std::min(result, get_minimax_value(curr_board, next, !p_do_maximize));
      }
    }
  }
  return result;
}

auto get_best_move(ttt::board const& p_board, ttt::cell::value p_turn) -> std::optional<ttt::cell::position> {
  std::optional<ttt::cell::position> result = std::nullopt;
  float best_value = -1.0;
  if (p_board.has_winner()) { return result; }
  for (uint16_t row = 0; row < 3; ++row) {
    for (uint16_t col = 0; col < 3; ++col) {
      const ttt::move attempt(row, col, p_turn);
      if (p_board.is_empty(attempt.pos())) {
        auto val = get_minimax_value(p_board, attempt, true);
        if (best_value < val) {
          best_value = val;
          result = attempt.pos();
        }
      }
    }
  }
  return result;
}


TEST_CASE("get_expected_value()") {
  const ttt::board brd;
  const ttt::move move_a(0,0,ttt::cell::value::EX);
  std::cout << "A utility: " << get_expected_value(brd, move_a) << std::endl;
  const ttt::move move_b(0,2,ttt::cell::value::EX);
  std::cout << "B utility: " << get_expected_value(brd, move_b) << std::endl;
  const ttt::move move_c(1,1,ttt::cell::value::EX);
  std::cout << "C utility: " << get_expected_value(brd, move_c) << std::endl;
  const ttt::move move_d(0,1,ttt::cell::value::EX);
  std::cout << "D utility: " << get_expected_value(brd, move_d) << std::endl;
}

// O X X
// X 0 0
// X E E

TEST_CASE("get_minimax_value()") {
  ttt::board brd;
  brd = brd.apply({0,0,ttt::cell::value::OH});
  brd = brd.apply({0,1,ttt::cell::value::EX});
  brd = brd.apply({0,2,ttt::cell::value::EX});
  brd = brd.apply({1,0,ttt::cell::value::EX});
  brd = brd.apply({1,1,ttt::cell::value::OH});
  brd = brd.apply({1,2,ttt::cell::value::OH});
  brd = brd.apply({2,0,ttt::cell::value::EX});
  std::cout << "Bad move: " << get_minimax_value(brd, {2,1,ttt::cell::value::OH}, true) << std::endl;
  std::cout << "Good move: " << get_minimax_value(brd, {2,2,ttt::cell::value::OH}, true) << std::endl;
}

TEST_CASE("get_best_move()") {
  ttt::board brd;
  brd = brd.apply({0,0,ttt::cell::value::OH});
  brd = brd.apply({0,1,ttt::cell::value::EX});
  brd = brd.apply({0,2,ttt::cell::value::EX});
  brd = brd.apply({1,0,ttt::cell::value::EX});
  brd = brd.apply({1,1,ttt::cell::value::OH});
  brd = brd.apply({1,2,ttt::cell::value::OH});
  brd = brd.apply({2,0,ttt::cell::value::EX});
  auto best_move = get_best_move(brd, ttt::cell::value::OH);
  CHECK(best_move.has_value());
  if (best_move.has_value()) {
    CHECK_EQ(best_move->row(),2);
    CHECK_EQ(best_move->col(),2);
  }
}
