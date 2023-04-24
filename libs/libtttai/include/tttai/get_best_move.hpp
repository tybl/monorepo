// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_TICTACTOE_LIBTTTAI_GETBESTMOVE_HPP
#define TYBL_TICTACTOE_LIBTTTAI_GETBESTMOVE_HPP

#include "ttt/board.hpp"
#include "ttt/cell.hpp"

#include <optional>

namespace tttai {

auto get_best_move(ttt::board const& p_board, ttt::cell::value p_turn) -> std::optional<ttt::cell::position>;

auto get_minimax_value(ttt::board const& p_board, ttt::move p_move, bool p_do_maximize) -> float;

} // namespace tttai

#endif // TYBL_TICTACTOE_LIBTTTAI_GETBESTMOVE_HPP
