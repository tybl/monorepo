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

  move(uint16_t p_row, uint16_t p_col, cell::value p_value);

  [[nodiscard]] auto col() const -> uint16_t;

  [[nodiscard]] auto pos() const -> cell::position;

  [[nodiscard]] auto row() const -> uint16_t;

  [[nodiscard]] auto value() const -> ttt::cell::value;

}; // class move

} // namespace ttt

#endif // TYBL_TICTACTOE_LIBTTT_MOVE_HPP
