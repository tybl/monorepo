// License: The Unlicense (https://unlicense.org)
#include "tttai/get_best_move.hpp"

#include "ttt/board.hpp"
#include "ttt/cell.hpp"

//#include <iostream>
#include <optional>

namespace tttai {

static auto score_game(ttt::board const& p_board) -> float {
  constexpr float WIN_VALUE = 10.0;
  if (p_board.is_winner(p_board.get_next_turn())) {
    throw std::runtime_error("The player won that did not make the last move. That shouldn't happen...");
  }
  if (p_board.is_winner(p_board.last_move().value())) {
    return WIN_VALUE - static_cast<float>(p_board.num_moves());
  }
  return 0;
}

auto minimax(ttt::board const& p_board) -> float {
  auto result = std::numeric_limits<float>::infinity();
  const auto turn = p_board.get_next_turn();
  for (uint16_t i = 0; i < 9; ++i) {
    const ttt::cell::position pos(i);
    if (p_board.is_empty(pos)) {
      auto n_board = p_board.apply({pos, turn});
      if (n_board.has_ended()) {
        auto utility = score_game(n_board);
        return utility;
      }
      auto val = -1 * minimax(n_board);
      result = std::min(result, val);
    }
  }
  return result;
}

auto get_best_move(ttt::board const& p_board) -> std::optional<ttt::cell::position> {
  std::optional<ttt::cell::position> result = std::nullopt;
  if (p_board.has_winner()) {
    return result;
  }

  float best_value = -1 * std::numeric_limits<float>::infinity();
  const auto turn = p_board.get_next_turn();
  for (uint16_t i = 0; i < 9; ++i) {
    const ttt::cell::position pos(i);
    if (p_board.is_empty(pos)) {
      auto n_board = p_board.apply({pos, turn});
      if (n_board.is_winner(turn) || n_board.is_tie()) {
        return pos;
      }
      auto val = -1 * minimax(n_board);
      if (best_value < val) {
        best_value = val;
        result = pos;
      }
    }
  }
  return result;
}

} // namespace tttai
