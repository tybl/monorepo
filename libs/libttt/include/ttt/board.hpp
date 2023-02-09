#ifndef TYBL_TICTACTOE_LIBTTT_BOARD_HPP
#define TYBL_TICTACTOE_LIBTTT_BOARD_HPP

#include "move.hpp"

namespace ttt {

class board {
  char m_board[3][3] = {0};

public:
  void display() const;

  void apply(move m);

  auto has_winner() const -> bool;

}; // class board

} // namespace ttt
#endif // TYBL_TICTACTOE_LIBTTT_BOARD_HPP
