#ifndef TYBL_TICTACTOE_LIBTTT_MOVE_HPP
#define TYBL_TICTACTOE_LIBTTT_MOVE_HPP

namespace ttt {

class move {
  int m_row;
  int m_col;
  char m_player;

public:
  move(int row, int col, char player);

  auto row() const -> int;

  auto col() const -> int;

  auto player() const -> char;

}; // class move

} // namespace ttt
#endif // TYBL_TICTACTOE_LIBTTT_MOVE_HPP
