// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_TICTACTOE_LIBTTT_BOARD_HPP
#define TYBL_TICTACTOE_LIBTTT_BOARD_HPP

#include "cell.hpp"
#include "move.hpp"

#include <array>
#include <cstdint>
#include <optional>

namespace ttt {

class board {
  static constexpr uint16_t NUM_ROWS = 3;
  static constexpr uint16_t NUM_COLS = 3;
  static constexpr auto NUM_CELLS = static_cast<size_t>(NUM_ROWS * NUM_COLS);
  std::array<cell::value, NUM_CELLS> m_board;

public:
  board();

  void display() const;

  [[nodiscard]] auto apply(move p_move) const -> board;

  [[gnu::pure, nodiscard]] auto has_winner() const -> bool;

  [[gnu::pure, nodiscard]] auto is_winner(cell::value p_player) const -> bool;

  [[gnu::pure, nodiscard]] auto is_tie() const -> bool;

  [[nodiscard]] auto get_winner() const -> std::optional<cell::value>;

  [[nodiscard]] auto get_cell(ttt::cell::position p_pos) const -> cell::value;

  [[nodiscard]] auto is_empty(ttt::cell::position p_pos) const -> bool;

  [[gnu::pure, nodiscard]] auto encode(ttt::cell::value p_player) const -> uint16_t;

  static auto decode(ttt::cell::value p_player, uint16_t p_value) -> board;

}; // class board

} // namespace ttt
#endif // TYBL_TICTACTOE_LIBTTT_BOARD_HPP
