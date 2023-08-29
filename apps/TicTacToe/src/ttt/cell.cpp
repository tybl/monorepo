#include "ttt/cell.hpp"

#include "ttt/bad_move.hpp"

#include <fmt/core.h>

namespace ttt {

cell::position::position(uint16_t p_index)
  : m_row(p_index / 3)
  , m_col(p_index % 3) {
  if (8 < p_index) {
    throw bad_move(fmt::format("p_index must have a value of less than 9. It had a value of {}", p_index));
  }
}

cell::position::position(uint16_t p_row, uint16_t p_col)
  : m_row(p_row)
  , m_col(p_col) {
  if (2 < p_row) {
    throw bad_move(fmt::format("p_row must have a value of 0, 1, or 2. It had a value of {}", p_row));
  }
  if (2 < p_col) {
    throw bad_move(fmt::format("p_col must have a value of 0, 1, or 2. It had a value of {}", p_col));
  }
}

[[nodiscard, gnu::pure]] auto cell::position::row() const -> uint16_t { return m_row; }

[[nodiscard, gnu::pure]] auto cell::position::col() const -> uint16_t { return m_col; }

[[nodiscard, gnu::pure]] auto cell::position::index() const -> std::size_t { return static_cast<std::size_t>(m_row * 3 + m_col); }

} // namespace ttt
