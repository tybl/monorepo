// License: The Unlicense (https://unlicense.org)
#include "game.hpp"

#include "ttt/cell.hpp"

#include <iostream>
#include <string>

void game::run() {
  std::string name;
  std::cout << "Welcome to tic tac toe. Please enter your name: ";
  std::cin >> name;
  std::cout << "Thank you, " << name << ". For this game, you will be 'X' and start first.\n";
  display_board();
  while (!m_board.has_winner()) {
    auto player_move = request_move(name);
    //m_board.display();
    m_board = m_board.apply(request_move(name));
    display_board();
  }
  m_board.display();
}

auto game::request_move(std::string const& p_name) -> ttt::move {
  std::cout << p_name << ", it is now your turn.\n";
  uint16_t row = 0;
  std::cout << "Please enter the row you would like to play: ";
  std::cin >> row;
  uint16_t col = 0;
  std::cout << "Please enter the column you would like to play: ";
  std::cin >> col;
  std::cout << "Thank you! ";
  return {row, col, static_cast<ttt::cell::value>('X')};
}

void game::display_board() const {
  std::cout << "The board currently looks like this:\n";
  m_board.display();
}
