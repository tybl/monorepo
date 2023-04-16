#include "ttt/cell.hpp"

namespace ttt {

    cell::position::position(uint16_t p_row, uint16_t p_col)
        : m_row(p_row)
        , m_col(p_col) {}

    [[nodiscard]] auto cell::position::row() const -> uint16_t { return m_row; }

    [[nodiscard]] auto cell::position::col() const -> uint16_t { return m_col; }

    [[nodiscard]] auto cell::position::index() const -> std::size_t { return static_cast<std::size_t>(m_row * 3 + m_col); }

} // namespace ttt
