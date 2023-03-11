#include "ttt/move.hpp"
#include "ttt/cell_value.hpp"

ttt::move::move(unsigned int p_row, unsigned int p_col, ttt::cell_value p_value)
  : m_row(p_row)
  , m_col(p_col)
  , m_value(p_value) {
  if (2 < m_row) {
    throw "something";
  }
  if (2 < m_col) {
    throw "something";
  }
  if (m_value != cell_value::EX && m_value != cell_value::OH) {
    throw "something";
  }
}

auto ttt::move::row() const -> unsigned int { return m_row; }

auto ttt::move::col() const -> unsigned int { return m_col; }

auto ttt::move::value() const -> ttt::cell_value { return m_value; }
