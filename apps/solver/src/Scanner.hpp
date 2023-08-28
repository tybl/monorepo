//
// Created by tybl on 1/5/23.
//

#ifndef SOLVE_SCANNER_HPP
#define SOLVE_SCANNER_HPP

#include "Token.hpp"

#include <string>
#include <vector>

class scanner {
  std::string m_source;
  std::vector<token> m_tokens;
  int m_start = 0;
  size_t m_current = 0;
  int m_line = 1;

public:
  explicit scanner(std::string p_source);

  std::vector<token> scan_tokens();

private:
  void add_token(TokenType p_type);

  void add_token(TokenType p_type, Object p_literal);

  char advance();

  [[nodiscard]] bool is_at_end() const;

  void scan_token();

  bool match(char p_expected);

  char peek();
};

#endif // SOLVE_SCANNER_HPP
