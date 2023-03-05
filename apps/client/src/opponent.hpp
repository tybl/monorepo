#ifndef TYBL_TICTACTOE_OPPONENT_HPP
#define TYBL_TICTACTOE_OPPONENT_HPP

#include <string>

struct opponent {
  opponent() = default;
  opponent(opponent &&) = default;
  opponent(opponent const&) = default;
  virtual ~opponent() = 0;
  auto operator=(opponent &&) -> opponent& = default;
  auto operator=(opponent const&) -> opponent& = default;

  virtual void sendto(std::string const& p_data) = 0;
  virtual auto recvfrom() -> std::string = 0;
};

#endif // TYBL_TICTACTOE_OPPONENT_HPP
