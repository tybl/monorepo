#include "game.hpp"

game::game(opponent& p_conn)
  : m_connector(p_conn) {}

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

auto game::make_move() -> ttt::move { return {0, 0, 'O'}; }
