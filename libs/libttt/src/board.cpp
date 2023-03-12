// License: The Unlicense (https://unlicense.org)
#include "ttt/board.hpp"
#include "ttt/cell.hpp"

#include <cstdint>
#include <fmt/format.h>

ttt::board::board()
  : m_board({
              cell::value::Empty,
    cell::value::Empty,
    cell::value::Empty,
    cell::value::Empty,
    cell::value::Empty,
    cell::value::Empty,
    cell::value::Empty,
    cell::value::Empty,
    cell::value::Empty,
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
  board_copy.m_board.at(p_move.pos().index()) = p_move.value();
  return board_copy;
}

auto ttt::board::has_winner() const -> bool {
  return (m_board[0] != cell::value::Empty && m_board[0] == m_board[1] && m_board[1] == m_board[2]) ||
         (m_board[3] != cell::value::Empty && m_board[3] == m_board[4] && m_board[4] == m_board[5]) ||
         (m_board[6] != cell::value::Empty && m_board[6] == m_board[7] && m_board[7] == m_board[8]) ||
         (m_board[0] != cell::value::Empty && m_board[0] == m_board[3] && m_board[3] == m_board[6]) ||
         (m_board[1] != cell::value::Empty && m_board[1] == m_board[4] && m_board[4] == m_board[7]) ||
         (m_board[2] != cell::value::Empty && m_board[2] == m_board[5] && m_board[5] == m_board[8]) ||
         (m_board[0] != cell::value::Empty && m_board[0] == m_board[4] && m_board[4] == m_board[8]) ||
         (m_board[2] != cell::value::Empty && m_board[2] == m_board[4] && m_board[4] == m_board[6]);
}

auto ttt::board::is_winner(ttt::cell::value p_player) const -> bool {
  return (m_board[0] == p_player && m_board[1] == p_player && m_board[2] == p_player) ||
         (m_board[3] == p_player && m_board[4] == p_player && m_board[5] == p_player) ||
         (m_board[6] == p_player && m_board[7] == p_player && m_board[8] == p_player) ||
         (m_board[0] == p_player && m_board[3] == p_player && m_board[6] == p_player) ||
         (m_board[1] == p_player && m_board[4] == p_player && m_board[7] == p_player) ||
         (m_board[2] == p_player && m_board[5] == p_player && m_board[8] == p_player) ||
         (m_board[0] == p_player && m_board[4] == p_player && m_board[8] == p_player) ||
         (m_board[2] == p_player && m_board[4] == p_player && m_board[6] == p_player);
}

auto ttt::board::is_tie() const -> bool {
  return !has_winner() &&
  m_board[0] != cell::value::Empty &&
  m_board[1] != cell::value::Empty &&
  m_board[2] != cell::value::Empty &&
  m_board[3] != cell::value::Empty &&
  m_board[4] != cell::value::Empty &&
  m_board[5] != cell::value::Empty &&
  m_board[6] != cell::value::Empty &&
  m_board[7] != cell::value::Empty &&
  m_board[8] != cell::value::Empty;
}

auto ttt::board::get_cell(ttt::cell::position p_pos) const -> cell::value {
  return m_board.at(p_pos.index());
}

auto ttt::board::is_empty(ttt::cell::position p_pos) const -> bool {
  return ttt::cell::value::Empty == get_cell(p_pos);
}

auto ttt::board::encode(ttt::cell::value p_player) const -> uint16_t {
  uint16_t result = 0;
  for (size_t row = 0; row < 3; ++row) {
    for (size_t col = 0; col < 3; ++col) {
      auto cell = m_board.at(row*3+col);
      const uint16_t digit = (cell != cell::value::Empty) ? ((cell == p_player) ? 1 : 2) : 0;
      result = static_cast<uint16_t>(result * 3) + digit;
    }
  }
  return result;
}

auto ttt::board::decode(ttt::cell::value p_player, uint16_t p_value) -> ttt::board {
  ttt::board result;
  const ttt::cell::value opponent = (ttt::cell::value::EX == p_player) ? ttt::cell::value::OH : ttt::cell::value::EX;
  for (size_t row = 2; row < 3; --row) {
    for (size_t col = 2; col < 3; --col) {
      auto cell = p_value % 3;
      p_value /= 3;
      result.m_board.at(row*3+col) = (0 != cell) ? ((1 == cell) ? p_player : opponent) : ttt::cell::value::Empty;
    }
  }
  return result;
}
