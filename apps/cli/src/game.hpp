// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_TICTACTOE_GAME_HPP
#define TYBL_TICTACTOE_GAME_HPP

#include "ttt/board.hpp"
#include "ttt/move.hpp"

class game {
  ttt::board m_board;

public:
  game() = default;

  void run();

private:
  static auto request_move(std::string const& p_name) -> ttt::move;
  void display_board() const;
}; // class game

#endif // TYBL_TICTACTOE_GAME_HPP
