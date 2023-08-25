//
// Created by tybl on 1/5/23.
//

#ifndef SOLVE_SCANNER_HPP
#define SOLVE_SCANNER_HPP

#include "Token.hpp"

#include <string>
#include <vector>

class Scanner {
  std::string m_source;
  std::vector<Token> tokens;
  int start = 0;
  int current = 0;
  int line = 1;

public:
  explicit Scanner(std::string source);

  std::vector<Token> scan_tokens();

private:
  void add_token(TokenType type);

  void add_token(TokenType type, Object literal);

  char advance();

  [[nodiscard]] bool is_at_end() const;

  void scan_token();

  bool match(char expected);

  char peek();
};

#endif // SOLVE_SCANNER_HPP
