// License: The Unlicense (https://unlicense.org)
#include "ttt/board.hpp"
#include "ttt/player.hpp"

#include <cstdint>
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

auto ttt::board::encode(ttt::player p_player) const -> uint16_t {
  uint16_t result = 0;
  for (size_t row = 0; row < 3; ++row) {
    for (size_t col = 0; col < 3; ++col) {
      auto cell = m_board.at(row).at(col);
      const uint16_t digit = (cell != player::Empty) ? ((cell == p_player) ? 1 : 2) : 0;
      result = static_cast<uint16_t>(result * 3) + digit;
    }
  }
  return result;
}

void ttt::board::decode(ttt::player p_player, uint16_t p_value) {
  const ttt::player opponent = (ttt::player::EX == p_player) ? ttt::player::OH : ttt::player::EX;
  for (size_t row = 2; row < 3; --row) {
    for (size_t col = 2; col < 3; --col) {
      auto cell = p_value % 3;
      p_value /= 3;
      m_board.at(row).at(col) = (0 != cell) ? ((1 == cell) ? p_player : opponent) : ttt::player::Empty;
    }
  }
}
