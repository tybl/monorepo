// License: The Unlicense (https://unlicense.org)
#include "ttt/move.hpp"

#include <fmt/core.h>

#include <stdexcept>

ttt::move::move(cell::position p_pos, cell::value p_value)
  : m_pos(p_pos)
  , m_value(p_value) {
  if (p_value != cell::value::EX && p_value != cell::value::OH) {
    throw std::runtime_error(
        fmt::format("p_value must have a value of 'X' or 'O'. It had a value of {}", static_cast<char>(p_value)));
  }
}

ttt::move::move(uint16_t p_row, uint16_t p_col, ttt::cell::value p_value)
  : m_pos(p_row, p_col)
  , m_value(p_value) {
  if (p_value != cell::value::EX && p_value != cell::value::OH) {
    throw std::runtime_error(
        fmt::format("p_value must have a value of 'X' or 'O'. It had a value of {}", static_cast<char>(p_value)));
  }
}

//[[gnu::pure]] auto ttt::move::col() const -> uint16_t { return m_pos.col(); }

[[gnu::pure]] auto ttt::move::pos() const -> cell::position { return m_pos; }

//[[gnu::pure]] auto ttt::move::row() const -> uint16_t { return m_pos.row(); }

[[gnu::pure]] auto ttt::move::value() const -> ttt::cell::value { return m_value; }
