#ifndef TYBL_TICTACTOE_TESTOPPONENT_HPP
#define TYBL_TICTACTOE_TESTOPPONENT_HPP

#include "opponent.hpp"

#include <string>
#include <vector>

class test_opponent : public opponent {
  std::size_t m_input_iteration;
  std::size_t m_output_iteration;
  std::vector<std::string> m_input;
  std::vector<std::string> m_expected_output;

public:
  test_opponent(std::vector<std::string> const& input, std::vector<std::string> const& expected_output);

  ~test_opponent() override;

  void sendto(std::string const& data) override;

  auto recvfrom() -> std::string override;
}; // class test_opponent

#endif // TYBL_TICTACTOE_TESTOPPONENT_HPP
