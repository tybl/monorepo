// License: The Unlicense (https://unlicense.org)
#include "game.hpp"

#include "ttt/cell.hpp"

#include <iostream>

void game::run() {
  while (!m_board.has_winner()) {
    m_board.display();
    m_board = m_board.apply(request_move());
  }
  m_board.display();
}

auto game::request_move() -> ttt::move {
  uint16_t row = 0;
  uint16_t col = 0;
  char plaha = ' ';
  std::cin >> plaha >> row >> col;
  return {row, col, static_cast<ttt::cell::value>(plaha)};
}
