// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_TICTACTOE_LIBTTT_MOVE_HPP
#define TYBL_TICTACTOE_LIBTTT_MOVE_HPP

#include "cell.hpp"

namespace ttt {

class move {
  cell::position m_pos;
  cell::value m_value;

public:
  move(unsigned int p_row, unsigned int p_col, cell::value p_value);

  [[nodiscard]] auto row() const -> unsigned int;

  [[nodiscard]] auto col() const -> unsigned int;

  [[nodiscard]] auto value() const -> ttt::cell::value;

}; // class move

} // namespace ttt

#endif // TYBL_TICTACTOE_LIBTTT_MOVE_HPP
