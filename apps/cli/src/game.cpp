// License: The Unlicense (https://unlicense.org)
#include "game.hpp"

#include "ttt/player.hpp"

#include <iostream>

void game::run() {
  while(!m_board.has_winner()) {
    m_board.display();
    m_board.apply(request_move());
  }
  m_board.display();
}

auto game::request_move() -> ttt::move {
  unsigned int row = 0;
  unsigned int col = 0;
  char plaha = ' ';
  std::cin >> plaha >> row >> col;
  return {row, col, static_cast<ttt::player>(plaha)};
}
