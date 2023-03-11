// License: The Unlicense (https://unlicense.org)
#include "ttt/board.hpp"
#include "ttt/cell_value.hpp"

#include <cstdint>
#include <fmt/format.h>

ttt::board::board()
  : m_board({
    cell_value::Empty,
    cell_value::Empty,
    cell_value::Empty,
    cell_value::Empty,
    cell_value::Empty,
    cell_value::Empty,
    cell_value::Empty,
    cell_value::Empty,
    cell_value::Empty,
    })
{}

void ttt::board::display() const {
  fmt::print(" {:1} | {:1} | {:1}\n",
             static_cast<char>(m_board[0]),
             static_cast<char>(m_board[1]),
             static_cast<char>(m_board[2]));
  fmt::print("---|---|---\n");
  fmt::print(" {:1} | {:1} | {:1}\n",
             static_cast<char>(m_board[3]),
             static_cast<char>(m_board[4]),
             static_cast<char>(m_board[5]));
  fmt::print("---|---|---\n");
  fmt::print(" {:1} | {:1} | {:1}\n",
             static_cast<char>(m_board[6]),
             static_cast<char>(m_board[7]),
             static_cast<char>(m_board[8]));
}

auto ttt::board::apply(move p_move) const -> board {
  ttt::board board_copy(*this);
  board_copy.m_board.at(position_to_index(p_move)) = p_move.value();
  return board_copy;
}

auto ttt::board::has_winner() const -> bool {
  return (m_board[0] != cell_value::Empty && m_board[0] == m_board[1] && m_board[1] == m_board[2]) ||
         (m_board[3] != cell_value::Empty && m_board[3] == m_board[4] && m_board[4] == m_board[5]) ||
         (m_board[6] != cell_value::Empty && m_board[6] == m_board[7] && m_board[7] == m_board[8]) ||
         (m_board[0] != cell_value::Empty && m_board[0] == m_board[3] && m_board[3] == m_board[6]) ||
         (m_board[1] != cell_value::Empty && m_board[1] == m_board[4] && m_board[4] == m_board[7]) ||
         (m_board[2] != cell_value::Empty && m_board[2] == m_board[5] && m_board[5] == m_board[8]) ||
         (m_board[0] != cell_value::Empty && m_board[0] == m_board[4] && m_board[4] == m_board[8]) ||
         (m_board[2] != cell_value::Empty && m_board[2] == m_board[4] && m_board[4] == m_board[6]);
}

auto ttt::board::is_winner(ttt::cell_value p_player) const -> bool {
  return (m_board[0] == p_player && m_board[1] == p_player && m_board[2] == p_player) ||
         (m_board[3] == p_player && m_board[4] == p_player && m_board[5] == p_player) ||
         (m_board[6] == p_player && m_board[7] == p_player && m_board[8] == p_player) ||
         (m_board[0] == p_player && m_board[3] == p_player && m_board[6] == p_player) ||
         (m_board[1] == p_player && m_board[4] == p_player && m_board[7] == p_player) ||
         (m_board[2] == p_player && m_board[5] == p_player && m_board[8] == p_player) ||
         (m_board[0] == p_player && m_board[4] == p_player && m_board[8] == p_player) ||
         (m_board[2] == p_player && m_board[4] == p_player && m_board[6] == p_player);
}

auto ttt::board::encode(ttt::cell_value p_player) const -> uint16_t {
  uint16_t result = 0;
  for (size_t row = 0; row < 3; ++row) {
    for (size_t col = 0; col < 3; ++col) {
      auto cell = m_board.at(row*3+col);
      const uint16_t digit = (cell != cell_value::Empty) ? ((cell == p_player) ? 1 : 2) : 0;
      result = static_cast<uint16_t>(result * 3) + digit;
    }
  }
  return result;
}

auto ttt::board::decode(ttt::cell_value p_player, uint16_t p_value) -> ttt::board {
  ttt::board result;
  const ttt::cell_value opponent = (ttt::cell_value::EX == p_player) ? ttt::cell_value::OH : ttt::cell_value::EX;
  for (size_t row = 2; row < 3; --row) {
    for (size_t col = 2; col < 3; --col) {
      auto cell = p_value % 3;
      p_value /= 3;
      result.m_board.at(row*3+col) = (0 != cell) ? ((1 == cell) ? p_player : opponent) : ttt::cell_value::Empty;
    }
  }
  return result;
}
