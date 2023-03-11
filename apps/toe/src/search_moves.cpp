#include "ttt/board.hpp"
#include "stats/distribution.hpp"

#include <doctest/doctest.h>

#include <iostream>

auto get_utility_of_move(ttt::board const& p_board, ttt::move p_move) -> float {
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
        dist += get_utility_of_move(curr_board, next);
      }
    }
  }
  return static_cast<float>(1.0 - dist.mean());
}

TEST_CASE("utility_of_move()") {
  const ttt::board brd;
  const ttt::move move_a(0,0,ttt::cell::value::EX);
  std::cout << "A utility: " << get_utility_of_move(brd, move_a) << std::endl;
  const ttt::move move_b(0,2,ttt::cell::value::EX);
  std::cout << "B utility: " << get_utility_of_move(brd, move_b) << std::endl;
  const ttt::move move_c(1,1,ttt::cell::value::EX);
  std::cout << "C utility: " << get_utility_of_move(brd, move_c) << std::endl;
  const ttt::move move_d(0,1,ttt::cell::value::EX);
  std::cout << "D utility: " << get_utility_of_move(brd, move_d) << std::endl;
}
