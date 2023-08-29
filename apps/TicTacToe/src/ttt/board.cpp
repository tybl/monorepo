// License: The Unlicense (https://unlicense.org)
#include "ttt/board.hpp"

#include "ttt/bad_move.hpp"
#include "ttt/cell.hpp"

#include <fmt/core.h>

#include <algorithm>
#include <iostream>

ttt::board::board() = default;

void ttt::board::display() const {
  for (uint16_t row = 0; row < NUM_ROWS; ++row) {
    if (0 != row) {
      fmt::print("---|---|---\n");
    }
    fmt::print(" {:1} | {:1} | {:1}\n",
               static_cast<char>(m_board.at(static_cast<unsigned>(row * NUM_COLS + 0))),
               static_cast<char>(m_board.at(static_cast<unsigned>(row * NUM_COLS + 1))),
               static_cast<char>(m_board.at(static_cast<unsigned>(row * NUM_COLS + 2))));
  }
}

auto ttt::board::apply(move p_move) const -> board {
  if (!is_empty(p_move.pos())) {
    throw bad_move("Position filled");
  }
  if (p_move.value() != get_next_turn()) {
    throw bad_move("Wrong turn");
  }
  ttt::board board_copy(*this);
  board_copy.m_board.at(p_move.pos().index()) = p_move.value();
  board_copy.m_history.push_back(p_move);
  return board_copy;
}

auto ttt::board::has_ended() const -> bool {
  return has_winner() || std::all_of(m_board.begin(), m_board.end(), [](cell::value p_val){ return p_val != cell::value::Empty; });
}

auto ttt::board::has_winner() const -> bool {
  //using enum ttt::cell::value;
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
         std::all_of(m_board.begin(), m_board.end(), [](cell::value p_val) { return p_val != cell::value::Empty; });
}

auto ttt::board::get_cell(ttt::cell::position p_pos) const -> cell::value { return m_board.at(p_pos.index()); }

auto ttt::board::get_next_turn() const -> ttt::cell::value {
  if (m_history.empty()) {
    return cell::value::EX;
  }
  return (cell::value::EX == m_history.back().value()) ? cell::value::OH : cell::value::EX;
}

auto ttt::board::is_empty(ttt::cell::position p_pos) const -> bool {
  return ttt::cell::value::Empty == get_cell(p_pos);
}

auto ttt::board::to_dot_string() const -> std::string {
  return fmt::format(R"({} [fontname="mono" fontcolor="{}" {}label="{}"];)",
                     dot_node_name(), dot_node_fontcolor(), dot_node_shape(), dot_node_label());
}

auto ttt::board::to_string() const -> std::string {
  std::string result;
  //for (auto mov : m_history) {
  //result.append(fmt::format("({},{}): {}\n", mov.pos().row(), mov.pos().col(), static_cast<char>(mov.value())));
  //}
  for (uint16_t row = 0; row < NUM_ROWS; ++row) {
    if (0 != row) {
      result.append(fmt::format("---|---|---\n"));
    }
    result.append(fmt::format(" {:1} | {:1} | {:1}\n",
                              static_cast<char>(m_board.at(static_cast<unsigned>(row * NUM_COLS + 0))),
                              static_cast<char>(m_board.at(static_cast<unsigned>(row * NUM_COLS + 1))),
                              static_cast<char>(m_board.at(static_cast<unsigned>(row * NUM_COLS + 2)))));
  }
  return result;
}

auto ttt::board::encode(ttt::cell::value p_player) const -> uint16_t {
  uint16_t result = 0;
  for (size_t row = 0; row < 3; ++row) {
    for (size_t col = 0; col < 3; ++col) {
      auto cell = m_board.at(row * 3 + col);
      const uint16_t digit = (cell != cell::value::Empty) ? ((cell == p_player) ? 1 : 2) : 0;
      result = static_cast<uint16_t>(static_cast<uint16_t>(result * 3) + digit);
    }
  }
  return result;
}


auto ttt::board::decode(ttt::cell::value p_player, uint16_t p_value) -> ttt::board {
  //using enum ttt::cell::value;
  ttt::board result;
  const ttt::cell::value opponent = (cell::value::EX == p_player) ? cell::value::OH : cell::value::EX;
  for (size_t row = 2; row < 3; --row) {
    for (size_t col = 2; col < 3; --col) {
      auto cell = p_value % 3;
      p_value /= 3;
      result.m_board.at(row * 3 + col) = (0 != cell) ? ((1 == cell) ? p_player : opponent) : cell::value::Empty;
    }
  }
  return result;
}

auto ttt::board::dot_node_name() const -> std::string {
  if (m_history.empty()) {
    return "Empty";
  }
  std::string result("m");
  for (auto const& m : m_history) {
    result += std::to_string(m.pos().index());
  }
  return result;
}

auto ttt::board::dot_node_fontcolor() const -> std::string {
  return "black";
}

auto ttt::board::dot_node_shape() const -> std::string {
  return has_ended() ? "" : "shape=none ";
}

auto ttt::board::dot_node_label() const -> std::string {
  std::string result;
  for (uint16_t row = 0; row < NUM_ROWS; ++row) {
    if (0 != row) {
      result.append("\\n");
    }
    result.append(fmt::format("{:1}{:1}{:1}", dot_cell(row,0), dot_cell(row, 1), dot_cell(row, 2)));
  }
  return result;
}

auto ttt::board::dot_cell(uint16_t p_row, uint16_t p_col) const -> char {
  auto val = m_board.at(static_cast<unsigned>(p_row * NUM_COLS + p_col));
  return (ttt::cell::value::Empty == val) ? '_' : static_cast<char>(val);
}
