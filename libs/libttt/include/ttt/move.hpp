// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_TICTACTOE_LIBTTT_MOVE_HPP
#define TYBL_TICTACTOE_LIBTTT_MOVE_HPP

#include "cell_value.hpp"

namespace ttt {

class move {
  unsigned int m_row;
  unsigned int m_col;
  cell_value m_value;

public:
  move(unsigned int p_row, unsigned int p_col, cell_value p_value);

  [[nodiscard]] auto row() const -> unsigned int;

  [[nodiscard]] auto col() const -> unsigned int;

  [[nodiscard]] auto value() const -> ttt::cell_value;

}; // class move

} // namespace ttt

#endif // TYBL_TICTACTOE_LIBTTT_MOVE_HPP
