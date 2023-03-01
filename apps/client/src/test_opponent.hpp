#ifndef TYBL_TICTACTOE_TESTOPPONENT_HPP
#define TYBL_TICTACTOE_TESTOPPONENT_HPP

#include "opponent.hpp"

#include <string>
#include <vector>

class test_opponent : public opponent {
  std::size_t m_input_iteration{0};
  std::size_t m_output_iteration{0};
  std::vector<std::string> m_input;
  std::vector<std::string> m_expected_output;

public:
  test_opponent(std::vector<std::string> p_input, std::vector<std::string> p_expected_output);

  test_opponent(test_opponent &&) = default;
  test_opponent(test_opponent const&) = default;

  ~test_opponent() override;

  auto operator=(test_opponent &&) -> test_opponent& = default;
  auto operator=(test_opponent const&) -> test_opponent& = default;

  void sendto(std::string const& p_data) override;

  auto recvfrom() -> std::string override;
}; // class test_opponent

#endif // TYBL_TICTACTOE_TESTOPPONENT_HPP
