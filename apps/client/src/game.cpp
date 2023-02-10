#include "game.hpp"

game::game(game_connector& conn)
  : m_connector(conn) {}

void game::run() {
  auto input = m_connector.recvfrom();
  m_connector.sendto("output1");
  input = m_connector.recvfrom();
  m_connector.sendto("output2");
  // if address is provided
  //    sendto(address, "game_id")
  // while(true)
  //    (game_id, move) = recvfrom()
  //    game = map[game_id];
  //    if (valid != game.apply(move))
  //       sendto(game.remote_ip, "invalid move")
  //       delete map[game_id]
  //       continue
  //    if (!game.finished())
  //       my_move = make_move(game)
  //       sendto(game.remote_ip, my_move)
}
ttt::move game::make_move() { return ttt::move(0, 0, 'O'); }
