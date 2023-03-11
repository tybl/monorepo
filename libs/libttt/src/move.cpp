#include "ttt/move.hpp"

ttt::move::move(unsigned int p_row, unsigned int p_col, ttt::cell::value p_value)
  : m_pos(p_row, p_col)
  , m_value(p_value) {
  if (2 < p_row) {
    throw "something";
  }
  if (2 < p_col) {
    throw "something";
  }
  if (p_value != cell::value::EX && p_value != cell::value::OH) {
    throw "something";
  }
}

auto ttt::move::row() const -> unsigned int { return m_pos.row(); }

auto ttt::move::col() const -> unsigned int { return m_pos.col(); }

auto ttt::move::value() const -> ttt::cell::value { return m_value; }
