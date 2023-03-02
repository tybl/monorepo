// License: The Unlicense (https://unlicense.org) 
#include "game.hpp"

#include <iostream>

void game::run() {
  while(!m_board.has_winner()) {
    m_board.display();
    auto mv = request_move();
    m_board.apply(mv);
  }
  m_board.display();
}

auto game::request_move() -> ttt::move {
  unsigned int x, y;
  char c;
  std::cin >> c >> x >> y;
  return {x, y, c};
}
