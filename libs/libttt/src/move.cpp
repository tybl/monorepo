#include "ttt/move.hpp"
#include "ttt/player.hpp"

ttt::move::move(unsigned int p_row, unsigned int p_col, player p_player)
  : m_row(p_row)
  , m_col(p_col)
  , m_player(p_player) {
  if (2 < m_row) {
    throw "something";
  }
  if (2 < m_col) {
    throw "something";
  }
  if (m_player != player::EX && m_player != player::OH) {
    throw "something";
  }
}

auto ttt::move::row() const -> unsigned int { return m_row; }

auto ttt::move::col() const -> unsigned int { return m_col; }

auto ttt::move::player_id() const -> player { return m_player; }
