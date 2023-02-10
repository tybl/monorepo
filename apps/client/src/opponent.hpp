#ifndef TYBL_TICTACTOE_OPPONENT_HPP
#define TYBL_TICTACTOE_OPPONENT_HPP

#include <string>

struct opponent {
  virtual ~opponent() = 0;
  virtual void sendto(std::string const& p_data) = 0;
  virtual auto recvfrom() -> std::string = 0;
};

#endif // TYBL_TICTACTOE_OPPONENT_HPP
