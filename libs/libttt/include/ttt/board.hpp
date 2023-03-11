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

  [[nodiscard]] auto has_winner() const -> bool;

  [[nodiscard]] auto is_winner(cell::value p_player) const -> bool;

  [[nodiscard]] auto get_winner() const -> std::optional<cell::value>;

  [[nodiscard]] auto encode(ttt::cell::value p_player) const -> uint16_t;

  static auto decode(ttt::cell::value p_player, uint16_t p_value) -> board;

private:
  static auto position_to_index(move p_move) -> size_t {
    return p_move.row() * 3 + p_move.col();
  }
}; // class board

} // namespace ttt
#endif // TYBL_TICTACTOE_LIBTTT_BOARD_HPP
