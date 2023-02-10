#include "test_opponent.hpp"

#include <iostream>

test_opponent::test_opponent(std::vector<std::string> p_input, std::vector<std::string> p_expected_output)
  : m_input(std::move(p_input))
  , m_expected_output(std::move(p_expected_output)) {}

test_opponent::~test_opponent() = default;

void test_opponent::sendto(std::string const& p_data) {
  if (p_data != m_expected_output.at(m_output_iteration)) {
    std::cerr << "sendto() called with different value than expected:\n"
              << "\tExpected: " << m_expected_output.at(m_output_iteration)
              << "\n\tReceived: " << p_data << std::endl;
  }
  m_output_iteration++;
}

auto test_opponent::recvfrom() -> std::string { return m_input.at(m_input_iteration++); }
