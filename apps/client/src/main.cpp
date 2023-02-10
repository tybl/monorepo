#include "game.hpp"
#include "test_connector.hpp"

int main() {
  test_connector conn({"input1", "input2"}, {"output1", "output2"});
  game my_game(conn);
  my_game.run();
}
