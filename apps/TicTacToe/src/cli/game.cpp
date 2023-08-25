// License: The Unlicense (https://unlicense.org)
#include "game.hpp"

#include "ttt/cell.hpp"
#include "tttai/get_best_move.hpp"

#include <iostream>
#include <string>

void game::run() {
  std::string name;
  std::cout << "Welcome to tic tac toe. Please enter your name: ";
  std::cin >> name;
  std::cout << "Thank you, " << name << ". For this game, you will be 'X' and start first.\n";
  display_board();
  while (!m_board.has_ended()) {
    m_board = m_board.apply(request_move(name));
    display_board();
    auto mov = tttai::get_best_move(m_board);
    if (mov.has_value()) {
      std::cout << "I will now take a turn and place my piece on row " << mov->row() << ", column " << mov->col() << ".\n";
      m_board = m_board.apply({*mov, ttt::cell::value::OH});
      display_board();
    }
  }
  if (m_board.is_winner(ttt::cell::value::EX)) {
    std::cout << "You won! Great job, " << name << "! I hope you have a nice day!\n";
  } else if (m_board.is_tie()) {
    std::cout << "It's a tie! Great job, " << name << "! That was tough! I hope you have a nice day!\n";
  }
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
