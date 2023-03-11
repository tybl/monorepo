// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_TICTACTOE_LIBTTT_CELLVALUE_HPP
#define TYBL_TICTACTOE_LIBTTT_CELLVALUE_HPP

namespace ttt {

enum class cell_value: char {
  Empty = ' ',
  EX = 'X',
  OH = 'O',
};

} // namespace ttt

#endif // TYBL_TICTACTOE_LIBTTT_CELLVALUE_HPP
