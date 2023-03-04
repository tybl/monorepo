// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_TICTACTOE_LIBTTT_MOVE_HPP
#define TYBL_TICTACTOE_LIBTTT_MOVE_HPP

#include "player.hpp"

namespace ttt {

class move {
  unsigned int m_row;
  unsigned int m_col;
  player m_player;

public:
  move(unsigned int p_row, unsigned int p_col, player p_player);

  [[nodiscard]] auto row() const -> unsigned int;

  [[nodiscard]] auto col() const -> unsigned int;

  [[nodiscard]] auto player_id() const -> player;

}; // class move

} // namespace ttt

#endif // TYBL_TICTACTOE_LIBTTT_MOVE_HPP
