// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_TICTACTOE_LIBTTT_BOARD_HPP
#define TYBL_TICTACTOE_LIBTTT_BOARD_HPP

#include "move.hpp"
#include "player.hpp"

#include <array>
#include <optional>

namespace ttt {

class board {
  std::array<std::array<player,3>,3> m_board;

public:
  board();

  void display() const;

  void apply(move p_move);

  [[nodiscard]] auto has_winner() const -> bool;

  [[nodiscard]] auto is_winner(player p_player) const -> bool;

  [[nodiscard]] auto get_winner() const -> std::optional<player>;

}; // class board

} // namespace ttt
#endif // TYBL_TICTACTOE_LIBTTT_BOARD_HPP
