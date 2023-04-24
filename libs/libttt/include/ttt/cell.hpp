// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_TICTACTOE_LIBTTT_CELL_HPP
#define TYBL_TICTACTOE_LIBTTT_CELL_HPP

#include <cstddef>
#include <cstdint>

namespace ttt {

struct cell {

  class position {
    uint16_t m_row;
    uint16_t m_col;

  public:
    explicit position(uint16_t p_index);

    position(uint16_t p_row, uint16_t p_col);

    [[nodiscard]] auto row() const -> uint16_t;

    [[nodiscard]] auto col() const -> uint16_t;

    [[nodiscard]] auto index() const -> std::size_t;

  }; // struct position

  enum class value : char {
    Empty = ' ',
    EX = 'X',
    OH = 'O',
  }; // enum class value

}; // struct cell

} // namespace ttt

#endif // TYBL_TICTACTOE_LIBTTT_CELL_HPP
