// License: The Unlicense (https://unlicense.org)

#include <fmt/core.h>

#include <array>
#include <optional>
#include <set>
#include <vector>

struct cell {

  class position {
    uint16_t m_row;
    uint16_t m_col;
  public:
    explicit position(uint16_t p_index);
    position(uint16_t p_row, uint16_t p_col);
    [[nodiscard]] auto row() const -> uint16_t;
    [[nodiscard]] auto col() const -> uint16_t;
    [[nodiscard]] auto index() const -> std::size_t;
  }; // struct position

  enum class value : char {
    Empty = ' ',
    EX = 'X',
    OH = 'O',
  }; // enum class value

}; // struct cell

constexpr auto next(cell::value p_turn) -> cell::value {
  return (cell::value::EX == p_turn) ? cell::value::OH : cell::value::EX;
}

class move {
  cell::position m_pos;
  cell::value m_value;
public:
  move(cell::position p_pos, cell::value p_value);
  move(uint16_t p_row, uint16_t p_col, cell::value p_value);
  //[[nodiscard]] auto col() const -> uint16_t;
  [[nodiscard]] auto pos() const -> cell::position;
  //[[nodiscard]] auto row() const -> uint16_t;
  [[nodiscard]] auto value() const -> cell::value;
}; // class move

class board {
  static constexpr uint16_t NUM_ROWS = 3;
  static constexpr uint16_t NUM_COLS = 3;
  static constexpr auto NUM_CELLS = static_cast<size_t>(NUM_ROWS * NUM_COLS);
  std::vector<move> m_history;
  std::array<cell::value, NUM_CELLS> m_board = {
      cell::value::Empty,
      cell::value::Empty,
      cell::value::Empty,
      cell::value::Empty,
      cell::value::Empty,
      cell::value::Empty,
      cell::value::Empty,
      cell::value::Empty,
      cell::value::Empty,
  };

public:
  board();
  [[nodiscard]] auto apply(move p_move) const -> board;
  [[gnu::pure, nodiscard]] auto has_ended() const -> bool;
  [[gnu::pure, nodiscard]] auto has_winner() const -> bool;
  [[gnu::pure, nodiscard]] auto is_winner(cell::value p_player) const -> bool;
  [[gnu::pure, nodiscard]] auto is_tie() const -> bool;
  [[nodiscard]] auto get_cell(cell::position p_pos) const -> cell::value;
  [[nodiscard]] auto is_empty(cell::position p_pos) const -> bool;
  [[nodiscard]] auto last_move() const -> move { return m_history.back(); }
  [[nodiscard]] auto num_moves() const -> size_t { return m_history.size(); }
  auto get_next_turn() const -> cell::value {
    if (m_history.empty()) {
      return cell::value::EX;
    }
    return next(m_history.back().value());
  }
  auto encode() const -> uint16_t;
  auto to_string() const -> std::string;
  auto operator<(board const& other) const -> bool { return m_board < other.m_board; }
}; // class board

auto minimax(const board& p_board, bool p_maximize) -> float;

auto get_best_move(board const& p_board) -> cell::position;

auto main() -> int {
  board brd;
  brd = brd.apply({0,0,cell::value::OH});
  brd = brd.apply({1,1,cell::value::EX});
  brd = brd.apply({0,2,cell::value::OH});
  brd = brd.apply({1,0,cell::value::EX});
  //brd = brd.apply({2,0,cell::value::OH});
  //brd = brd.apply({1,2,cell::value::EX});
  //brd = brd.apply({2,1,cell::value::OH});
  //brd = brd.apply({2,2,cell::value::EX});
  get_best_move(brd);
}

cell::position::position(uint16_t p_index)
    : m_row(p_index / 3)
    , m_col(p_index % 3)
{
  if (8 < p_index) {
    throw std::runtime_error(fmt::format("p_index must have a value of 8 or less. It had a value of {}", p_index));
  }
}

cell::position::position(uint16_t p_row, uint16_t p_col)
    : m_row(p_row)
    , m_col(p_col)
{
  if (2 < p_row) {
    throw std::runtime_error(fmt::format("p_row must have a value of 0, 1, or 2. It had a value of {}", p_row));
  }
  if (2 < p_col) {
    throw std::runtime_error(fmt::format("p_col must have a value of 0, 1, or 2. It had a value of {}", p_col));
  }
}

[[nodiscard]] auto cell::position::row() const -> uint16_t { return m_row; }

[[nodiscard]] auto cell::position::col() const -> uint16_t { return m_col; }

[[nodiscard]] auto cell::position::index() const -> std::size_t { return static_cast<std::size_t>(m_row * 3 + m_col); }

move::move(cell::position p_pos, cell::value p_value)
    : m_pos(p_pos)
    , m_value(p_value) {
  if (p_value != cell::value::EX && p_value != cell::value::OH) {
    throw std::runtime_error(
        fmt::format("p_value must have a value of 'X' or 'O'. It had a value of {}", static_cast<char>(p_value)));
  }
}

move::move(uint16_t p_row, uint16_t p_col, cell::value p_value)
    : m_pos(p_row, p_col)
    , m_value(p_value) {
  if (p_value != cell::value::EX && p_value != cell::value::OH) {
    throw std::runtime_error(
        fmt::format("p_value must have a value of 'X' or 'O'. It had a value of {}", static_cast<char>(p_value)));
  }
}

//[[gnu::pure]] auto ttt::move::col() const -> uint16_t { return m_pos.col(); }

[[gnu::pure]] auto move::pos() const -> cell::position { return m_pos; }

//[[gnu::pure]] auto ttt::move::row() const -> uint16_t { return m_pos.row(); }

[[gnu::pure]] auto move::value() const -> cell::value { return m_value; }

board::board() = default;

auto board::apply(move p_move) const -> board {
  board board_copy(*this);
  board_copy.m_board.at(p_move.pos().index()) = p_move.value();
  board_copy.m_history.push_back(p_move);
  return board_copy;
}

auto board::has_ended() const -> bool {
  return has_winner() || std::all_of(m_board.begin(), m_board.end(), [](cell::value p_val){ return p_val != cell::value::Empty; });
}

auto board::has_winner() const -> bool {
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

auto board::is_winner(cell::value p_player) const -> bool {
  return (m_board[0] == p_player && m_board[1] == p_player && m_board[2] == p_player) ||
         (m_board[3] == p_player && m_board[4] == p_player && m_board[5] == p_player) ||
         (m_board[6] == p_player && m_board[7] == p_player && m_board[8] == p_player) ||
         (m_board[0] == p_player && m_board[3] == p_player && m_board[6] == p_player) ||
         (m_board[1] == p_player && m_board[4] == p_player && m_board[7] == p_player) ||
         (m_board[2] == p_player && m_board[5] == p_player && m_board[8] == p_player) ||
         (m_board[0] == p_player && m_board[4] == p_player && m_board[8] == p_player) ||
         (m_board[2] == p_player && m_board[4] == p_player && m_board[6] == p_player);
}

auto board::is_tie() const -> bool {
  return !has_winner() &&
         std::all_of(m_board.begin(), m_board.end(), [](cell::value p_val) { return p_val != cell::value::Empty; });
}

auto board::get_cell(cell::position p_pos) const -> cell::value { return m_board.at(p_pos.index()); }

auto board::is_empty(cell::position p_pos) const -> bool {
  return cell::value::Empty == get_cell(p_pos);
}

auto board::encode() const -> uint16_t {
  uint16_t result = 0;
  for (size_t row = 0; row < 3; ++row) {
    for (size_t col = 0; col < 3; ++col) {
      auto cell = m_board.at(row * 3 + col);
      const uint16_t digit = (cell != cell::value::Empty) ? ((cell == cell::value::EX) ? 1 : 2) : 0;
      result = static_cast<uint16_t>(result * 3) + digit;
    }
  }
  return result;
}

auto board::to_string() const -> std::string {
  std::string result;
  //for (auto mov : m_history) {
    //result.append(fmt::format("({},{}): {}\n", mov.pos().row(), mov.pos().col(), static_cast<char>(mov.value())));
  //}
  for (uint16_t row = 0; row < NUM_ROWS; ++row) {
    if (0 != row) {
      result.append(fmt::format("---|---|---\n"));
    }
    result.append(fmt::format(" {:1} | {:1} | {:1}\n", static_cast<char>(m_board.at(row * NUM_COLS + 0)),
                static_cast<char>(m_board.at(static_cast<unsigned>(row * NUM_COLS + 1))),
                static_cast<char>(m_board.at(static_cast<unsigned>(row * NUM_COLS + 2)))));
  }
  return result;
}

static auto score_game(board const& p_board, bool p_maximize) -> float {
  constexpr float WIN_VALUE = 10.0;
  auto player = p_board.last_move().value();
  if (p_board.is_winner(next(player))) {
    throw std::runtime_error("The player won that did not take the last turn. That shouldn't happen...");
  }
  auto depth = static_cast<float>(p_board.num_moves());
  if (p_board.is_winner(player)) {
    float result = WIN_VALUE - depth;
    if (!p_maximize) {
      result = depth - WIN_VALUE;
    }
    return result;
  }
  return 0;
}

auto minimax(board const& p_board, bool p_maximize) -> float {
  if (p_board.has_ended()) {
    return score_game(p_board, p_maximize);
  }
  if (p_maximize) {
    float result = 1 * std::numeric_limits<float>::infinity();
    for (uint16_t i = 0; i < 9; ++i) {
      const cell::position pos(i);
      if (p_board.is_empty(pos)) {
        auto child_board = p_board.apply(move(pos, p_board.get_next_turn()));
        auto res = minimax(child_board, false);
        result = std::min(result, res);
      }
    }
    return result;
  }
  float result = -1 * std::numeric_limits<float>::infinity();
  for (uint16_t i = 0; i < 9; ++i) {
    const cell::position pos(i);
    if (p_board.is_empty(pos)) {
      auto child_board = p_board.apply(move(pos, p_board.get_next_turn()));
      auto res = minimax(child_board, true);
      result = std::max(result, res);
    }
  }
  return result;
}

auto get_best_move(board const& p_board) -> cell::position {
  uint16_t max_index = 0;
  float max_value = -1 * std::numeric_limits<float>::infinity();
  const cell::value turn = p_board.get_next_turn();
  for (uint16_t i = 0; i < 9; ++i) {
    const cell::position pos(i);
    if (p_board.is_empty(pos)) {
      auto child_board = p_board.apply(move(pos, turn));
      auto val = minimax(child_board, true);
      fmt::print("{}: {}\n", i, val);
      if (val > max_value) {
        max_index = i;
        max_value = val;
      }
    }
  }
  return cell::position(max_index);
}
