#include "ttt/move.hpp"

#include <stdexcept>

ttt::move::move(uint16_t p_row, uint16_t p_col, ttt::cell::value p_value)
  : m_pos(p_row, p_col)
  , m_value(p_value) {
  if (2 < p_row) {
    throw std::runtime_error("p_row must have a value of 0, 1, or 2");
  }
  if (2 < p_col) {
    throw std::runtime_error("p_col must have a value of 0, 1, or 2");
  }
  if (p_value != cell::value::EX && p_value != cell::value::OH) {
    throw std::runtime_error("p_value must have a value of EX or OH");
  }
}

[[gnu::pure]] auto ttt::move::col() const -> uint16_t { return m_pos.col(); }

[[gnu::pure]] auto ttt::move::pos() const -> cell::position { return m_pos; }

[[gnu::pure]] auto ttt::move::row() const -> uint16_t { return m_pos.row(); }

[[gnu::pure]] auto ttt::move::value() const -> ttt::cell::value { return m_value; }
