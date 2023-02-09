#ifndef TYBL_TICTACTOE_GAME_HPP
#define TYBL_TICTACTOE_GAME_HPP

#include "game_connector.hpp"
#include "ttt/move.hpp"

class game {
  game_connector& m_connector;

public:
  explicit game(game_connector& conn);

  void run();

private:
  ttt::move make_move();
}; // class game

#endif // TYBL_TICTACTOE_GAME_HPP
