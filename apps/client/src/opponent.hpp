#ifndef TYBL_TICTACTOE_OPPONENT_HPP
#define TYBL_TICTACTOE_OPPONENT_HPP

#include <string>

struct opponent {
  virtual ~opponent() = 0;
  virtual void sendto(std::string const& data) = 0;
  virtual std::string recvfrom() = 0;
};

#endif // TYBL_TICTACTOE_OPPONENT_HPP
