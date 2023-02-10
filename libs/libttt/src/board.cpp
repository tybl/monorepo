#include "ttt/board.hpp"

#include <fmt/core.h>

void ttt::board::display() const {
  fmt::print("{} | {} | {}\n", m_board[0][0], m_board[0][1], m_board[0][2]);
  fmt::print("{} | {} | {}\n", m_board[1][0], m_board[1][1], m_board[1][2]);
  fmt::print("{} | {} | {}\n", m_board[2][0], m_board[2][1], m_board[2][2]);
}

void ttt::board::apply(move p_move) { m_board.at(p_move.row()).at(p_move.col()) = p_move.player(); }

auto ttt::board::has_winner() const -> bool {
  return (m_board[0][0] == m_board[0][1] && m_board[0][1] == m_board[0][2]) ||
         (m_board[1][0] == m_board[1][1] && m_board[1][1] == m_board[1][2]) ||
         (m_board[2][0] == m_board[2][1] && m_board[2][1] == m_board[2][2]) ||
         (m_board[0][0] == m_board[1][0] && m_board[1][0] == m_board[2][0]) ||
         (m_board[0][1] == m_board[1][1] && m_board[1][1] == m_board[2][1]) ||
         (m_board[0][2] == m_board[1][2] && m_board[1][2] == m_board[2][2]) ||
         (m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2]) ||
         (m_board[0][2] == m_board[1][1] && m_board[1][1] == m_board[2][0]);
}
