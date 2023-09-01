// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_TICTACTOE_LIBTTT_BADMOVE_HPP
#define TYBL_TICTACTOE_LIBTTT_BADMOVE_HPP

#include <stdexcept>

namespace ttt {

struct bad_move : public std::runtime_error {
  using std::runtime_error::runtime_error;
  using std::runtime_error::what;
};

} // namespace ttt

#endif // TYBL_TICTACTOE_LIBTTT_BADMOVE_HPP
