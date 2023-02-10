#include "ttt/move.hpp"

ttt::move::move(int row, int col, char player)
  : m_row(row)
  , m_col(col)
  , m_player(player) {
  if (0 > m_row || m_row > 2) {
    throw "something";
  }
  if (0 > m_col || m_col > 2) {
    throw "something";
  }
  if (m_player != 'X' && m_player != 'O') {
    throw "something";
  }
}

auto ttt::move::row() const -> int { return m_row; }

auto ttt::move::col() const -> int { return m_col; }

auto ttt::move::player() const -> char { return m_player; }
