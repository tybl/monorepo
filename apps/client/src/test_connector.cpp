#include "test_connector.hpp"

#include <iostream>

test_connector::test_connector(std::vector<std::string> const& input, std::vector<std::string> const& expected_output)
  : m_input_iteration(0)
  , m_output_iteration(0)
  , m_input(input)
  , m_expected_output(expected_output) {}

test_connector::~test_connector() = default;

void test_connector::sendto(std::string const& data) {
  if (data != m_expected_output.at(m_output_iteration)) {
    std::cerr << "sendto() called with different value than expected:\n"
              << "\tExpected: " << m_expected_output.at(m_output_iteration) << "\n\tReceived: " << data << std::endl;
  }
  m_output_iteration++;
}

std::string test_connector::recvfrom() { return m_input.at(m_input_iteration++); }
