#ifndef TYBL_TICTACTOE_LIBTTT_MOVE_HPP
#define TYBL_TICTACTOE_LIBTTT_MOVE_HPP

namespace ttt {

class move {
  unsigned int m_row;
  unsigned int m_col;
  char m_player;

public:
  move(unsigned int p_row, unsigned int p_col, char p_player);

  [[nodiscard]] auto row() const -> unsigned int;

  [[nodiscard]] auto col() const -> unsigned int;

  [[nodiscard]] auto player() const -> char;

}; // class move

} // namespace ttt
#endif // TYBL_TICTACTOE_LIBTTT_MOVE_HPP
