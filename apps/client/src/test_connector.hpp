#ifndef TYBL_TICTACTOE_TESTCONNECTOR_HPP
#define TYBL_TICTACTOE_TESTCONNECTOR_HPP

#include "game_connector.hpp"

#include <string>
#include <vector>

class test_connector
    : public game_connector
{
  std::size_t m_input_iteration;
  std::size_t m_output_iteration;
  std::vector<std::string> m_input;
  std::vector<std::string> m_expected_output;

public:
  test_connector(std::vector<std::string> const& input,
                 std::vector<std::string> const& expected_output);

  ~test_connector() override;

  void sendto(std::string const& data) override;

  auto recvfrom() -> std::string override;
}; // class test_connector

#endif // TYBL_TICTACTOE_TESTCONNECTOR_HPP