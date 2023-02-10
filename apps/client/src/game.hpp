#ifndef TYBL_TICTACTOE_GAME_HPP
#define TYBL_TICTACTOE_GAME_HPP

#include "opponent.hpp"
#include "ttt/move.hpp"

class game {
  opponent& m_connector;

public:
  explicit game(opponent& conn);

  void run();

private:
  ttt::move make_move();
}; // class game

#endif // TYBL_TICTACTOE_GAME_HPP
