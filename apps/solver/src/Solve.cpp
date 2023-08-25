#include "Solve.hpp"

#include "Scanner.hpp"

#include <fstream>
#include <iostream>

void Solve::error(int line, std::string const& message) { report(line, "", message); }

void Solve::report(int line, std::string const& where, std::string const& message) {
  std::cerr << "[line " << line << "] Error" << where << ": " << message << std::endl;
  m_had_error = true;
}

void Solve::run(std::string const& input) {
  Scanner scanner(input);
  auto tokens = scanner.scan_tokens();
  for (auto const& token : tokens) {
    std::cout << token.to_string() << std::endl;
  }
}

void Solve::run_file(std::string const& path) const {
  std::ifstream file(path);
  std::string input(std::istreambuf_iterator<char>{file}, {});
  run(input);
  if (m_had_error)
    exit(65);
}

void Solve::run_prompt() {
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
