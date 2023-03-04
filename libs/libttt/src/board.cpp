// License: The Unlicense (https://unlicense.org)
#include "ttt/board.hpp"

#include <fmt/format.h>

ttt::board::board()
  : m_board({
    player::Empty,
    player::Empty,
    player::Empty,
    player::Empty,
    player::Empty,
    player::Empty,
    player::Empty,
    player::Empty,
    player::Empty,
    })
{}

void ttt::board::display() const {
  fmt::print(" {:1} | {:1} | {:1}\n",
             static_cast<char>(m_board[0][0]),
             static_cast<char>(m_board[0][1]),
             static_cast<char>(m_board[0][2]));
  fmt::print("---|---|---\n");
  fmt::print(" {:1} | {:1} | {:1}\n",
             static_cast<char>(m_board[1][0]),
             static_cast<char>(m_board[1][1]),
             static_cast<char>(m_board[1][2]));
  fmt::print("---|---|---\n");
  fmt::print(" {:1} | {:1} | {:1}\n",
             static_cast<char>(m_board[2][0]),
             static_cast<char>(m_board[2][1]),
             static_cast<char>(m_board[2][2]));
}

void ttt::board::apply(move p_move) { m_board.at(p_move.row()).at(p_move.col()) = p_move.player_id(); }

auto ttt::board::has_winner() const -> bool {
  return (m_board[0][0] != player::Empty && m_board[0][0] == m_board[0][1] && m_board[0][1] == m_board[0][2]) ||
         (m_board[1][0] != player::Empty && m_board[1][0] == m_board[1][1] && m_board[1][1] == m_board[1][2]) ||
         (m_board[2][0] != player::Empty && m_board[2][0] == m_board[2][1] && m_board[2][1] == m_board[2][2]) ||
         (m_board[0][0] != player::Empty && m_board[0][0] == m_board[1][0] && m_board[1][0] == m_board[2][0]) ||
         (m_board[0][1] != player::Empty && m_board[0][1] == m_board[1][1] && m_board[1][1] == m_board[2][1]) ||
         (m_board[0][2] != player::Empty && m_board[0][2] == m_board[1][2] && m_board[1][2] == m_board[2][2]) ||
         (m_board[0][0] != player::Empty && m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2]) ||
         (m_board[0][2] != player::Empty && m_board[0][2] == m_board[1][1] && m_board[1][1] == m_board[2][0]);
}

auto ttt::board::is_winner(ttt::player p_player) const -> bool {
  return (m_board[0][0] == p_player && m_board[0][1] == p_player && m_board[0][2] == p_player) ||
         (m_board[1][0] == p_player && m_board[1][1] == p_player && m_board[1][2] == p_player) ||
         (m_board[2][0] == p_player && m_board[2][1] == p_player && m_board[2][2] == p_player) ||
         (m_board[0][0] == p_player && m_board[1][0] == p_player && m_board[2][0] == p_player) ||
         (m_board[0][1] == p_player && m_board[1][1] == p_player && m_board[2][1] == p_player) ||
         (m_board[0][2] == p_player && m_board[1][2] == p_player && m_board[2][2] == p_player) ||
         (m_board[0][0] == p_player && m_board[1][1] == p_player && m_board[2][2] == p_player) ||
         (m_board[0][2] == p_player && m_board[1][1] == p_player && m_board[2][0] == p_player);
}
