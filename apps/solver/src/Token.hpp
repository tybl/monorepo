//
// Created by tybl on 1/5/23.
//

#ifndef SOLVE_TOKEN_HPP
#define SOLVE_TOKEN_HPP

#include "Object.hpp"
#include "TokenType.hpp"

#include <string>
#include <utility>

class token {
  TokenType m_type;
  std::string m_lexeme;
  Object m_literal;
  int m_line;

public:
  token(TokenType p_type, std::string p_lexeme, Object p_literal, int p_line);

  [[nodiscard]] auto to_string() const -> std::string;
};
#endif // SOLVE_TOKEN_HPP
