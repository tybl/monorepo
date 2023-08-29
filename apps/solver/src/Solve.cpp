#include "Solve.hpp"

#include "Scanner.hpp"

#include <fstream>
#include <iostream>

void solve::error(int p_line, std::string const& p_message) { report(p_line, "", p_message); }

void solve::report(int p_line, std::string const& p_where, std::string const& p_message) {
  std::cerr << "[line " << p_line << "] Error" << p_where << ": " << p_message << std::endl;
  m_had_error = true;
}

void solve::run(std::string const& p_input) {
  scanner scanner(p_input);
  auto tokens = scanner.scan_tokens();
  for (auto const& token : tokens) {
    std::cout << token.to_string() << std::endl;
  }
}

void solve::run_file(std::string const& p_path) const {
  std::ifstream file(p_path);
  std::string input(std::istreambuf_iterator<char>{file}, {});
  run(input);
  if (m_had_error)
    exit(65);
}

void solve::run_prompt() {
  std::string input;
  while (true) {
    std::cout << "> ";
    std::getline(std::cin, input);
    if (input.empty())
      break;
    run(input);
    m_had_error = false;
  }
}
