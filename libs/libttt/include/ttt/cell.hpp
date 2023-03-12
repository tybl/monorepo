// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_TICTACTOE_LIBTTT_CELL_HPP
#define TYBL_TICTACTOE_LIBTTT_CELL_HPP

#include <cstdint>

namespace ttt {

struct cell {

class position {
  uint16_t m_row;
  uint16_t m_col;
public:

  position(uint16_t p_row, uint16_t p_col): m_row(p_row), m_col(p_col) {}

  [[nodiscard]] auto row() const -> uint16_t { return m_row; }

  [[nodiscard]] auto col() const -> uint16_t { return m_col; }

  [[nodiscard]] auto index() const -> std::size_t { return static_cast<std::size_t>(m_row * 3 + m_col); }

}; // struct position

enum class value: char {
  Empty = ' ',
  EX = 'X',
  OH = 'O',
}; // enum class value

}; // struct cell

} // namespace ttt

#endif // TYBL_TICTACTOE_LIBTTT_CELL_HPP
