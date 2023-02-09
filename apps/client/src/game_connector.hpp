#ifndef TYBL_TICTACTOE_GAMECONNECTOR_HPP
#define TYBL_TICTACTOE_GAMECONNECTOR_HPP

#include <string>

struct game_connector {
  virtual ~game_connector() = 0;
  virtual void sendto(std::string const& data) = 0;
  virtual std::string recvfrom() = 0;
};

#endif // TYBL_TICTACTOE_GAMECONNECTOR_HPP
