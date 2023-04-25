#include "tttai/get_best_move.hpp"

#include "ttt/board.hpp"
#include "ttt/cell.hpp"

#include <optional>

namespace tttai {

static auto score_game(ttt::board const& p_board, bool p_maximize) -> float {
  constexpr float WIN_VALUE = 10.0;
  if (p_board.is_winner(p_board.get_next_turn())) {
    throw std::runtime_error("The player won that did not take the last turn. That shouldn't happen...");
  }
  auto depth = static_cast<float>(p_board.num_moves());
  auto player = p_board.last_move().value();
  if (p_board.is_winner(player)) {
    float result = WIN_VALUE - depth;
    if (!p_maximize) {
      result = depth - WIN_VALUE;
    }
    return result;
  }
  return 0;
}

auto minimax(ttt::board const& p_board, bool p_maximize) -> float {
  if (p_board.has_ended()) {
    return score_game(p_board, p_maximize);
  }
  if (p_maximize) {
    float result = 1 * std::numeric_limits<float>::infinity();
    for (uint16_t i = 0; i < 9; ++i) {
      const ttt::cell::position pos(i);
      if (p_board.is_empty(pos)) {
        auto child_board = p_board.apply(ttt::move(pos, p_board.get_next_turn()));
        auto res = minimax(child_board, false);
        result = std::min(result, res);
      }
    }
    return result;
  }
  float result = -1 * std::numeric_limits<float>::infinity();
  for (uint16_t i = 0; i < 9; ++i) {
    const ttt::cell::position pos(i);
    if (p_board.is_empty(pos)) {
      auto child_board = p_board.apply(ttt::move(pos, p_board.get_next_turn()));
      auto res = minimax(child_board, true);
      result = std::max(result, res);
    }
  }
  return result;
}
auto get_minimax_value(ttt::board const& p_board, ttt::move p_move, bool p_do_maximize) -> float {
  auto curr_board = p_board.apply(p_move);
  if (curr_board.has_winner()) {
    return 1.0;
  }
  if (curr_board.is_tie()) {
    return 0.0;
  }
  const ttt::cell::value player =
      (ttt::cell::value::EX == p_move.value()) ? ttt::cell::value::OH : ttt::cell::value::EX;
  if (p_do_maximize) {
    float result = -1.0;
    for (uint16_t row = 0; row < 3; ++row) {
      for (uint16_t col = 0; col < 3; ++col) {
        const ttt::move next(row, col, player);
        if (curr_board.is_empty(next.pos())) {
          result = std::max(result, get_minimax_value(curr_board, next, !p_do_maximize));
        }
      }
    }
    return result;
  }
  float result = 1.0;
  for (uint16_t row = 0; row < 3; ++row) {
    for (uint16_t col = 0; col < 3; ++col) {
      const ttt::move next(row, col, player);
      if (curr_board.is_empty(next.pos())) {
        result = std::min(result, get_minimax_value(curr_board, next, !p_do_maximize));
      }
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
      const ttt::move attempt(pos, turn);
      auto val = get_minimax_value(p_board, attempt, true);
      if (best_value < val) {
        best_value = val;
        result = pos;
      }
    }
  }
  return result;
}

} // namespace tttai