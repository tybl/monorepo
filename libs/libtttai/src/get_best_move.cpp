#include "tttai/get_best_move.hpp"

#include "ttt/board.hpp"
#include "ttt/cell.hpp"

#include <optional>

auto tttai::get_minimax_value(ttt::board const& p_board, ttt::move p_move, bool p_do_maximize) -> float {
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

auto tttai::get_best_move(ttt::board const& p_board, ttt::cell::value p_turn) -> std::optional<ttt::cell::position> {
  std::optional<ttt::cell::position> result = std::nullopt;
  float best_value = -1.0;
  if (p_board.has_winner()) {
    return result;
  }
  for (uint16_t row = 0; row < 3; ++row) {
    for (uint16_t col = 0; col < 3; ++col) {
      const ttt::move attempt(row, col, p_turn);
      if (p_board.is_empty(attempt.pos())) {
        auto val = get_minimax_value(p_board, attempt, true);
        if (best_value < val) {
          best_value = val;
          result = attempt.pos();
        }
      }
    }
  }
  return result;
}
