#include "ttt/move.hpp"

ttt::move::move(unsigned int p_row, unsigned int p_col, char p_player)
  : m_row(p_row)
  , m_col(p_col)
  , m_player(p_player) {
  if (2 < m_row) {
    throw "something";
  }
  if (2 < m_col) {
    throw "something";
  }
  if (m_player != 'X' && m_player != 'O') {
    throw "something";
  }
}

auto ttt::move::row() const -> unsigned int { return m_row; }

auto ttt::move::col() const -> unsigned int { return m_col; }

auto ttt::move::player() const -> char { return m_player; }
