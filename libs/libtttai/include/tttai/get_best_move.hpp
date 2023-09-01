// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_TICTACTOE_LIBTTTAI_GETBESTMOVE_HPP
#define TYBL_TICTACTOE_LIBTTTAI_GETBESTMOVE_HPP

#include "ttt/board.hpp"
#include "ttt/cell.hpp"

#include <optional>

namespace tttai {

auto get_best_move(ttt::board const& p_board) -> std::optional<ttt::cell::position>;

auto minimax(ttt::board const& p_board) -> float;

} // namespace tttai

#endif // TYBL_TICTACTOE_LIBTTTAI_GETBESTMOVE_HPP
