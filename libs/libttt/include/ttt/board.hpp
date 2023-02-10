#ifndef TYBL_TICTACTOE_LIBTTT_BOARD_HPP
#define TYBL_TICTACTOE_LIBTTT_BOARD_HPP

#include "move.hpp"

#include <array>

namespace ttt {

class board {
  std::array<std::array<char,3>,3> m_board;

public:
  void display() const;

  void apply(move p_move);

  [[nodiscard]] auto has_winner() const -> bool;

}; // class board

} // namespace ttt
#endif // TYBL_TICTACTOE_LIBTTT_BOARD_HPP
