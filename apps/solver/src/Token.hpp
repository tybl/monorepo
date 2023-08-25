//
// Created by tybl on 1/5/23.
//

#ifndef SOLVE_TOKEN_HPP
#define SOLVE_TOKEN_HPP

#include "Object.hpp"
#include "TokenType.hpp"

#include <string>
#include <utility>

class Token {
  TokenType type;
  std::string lexeme;
  Object literal;
  int line;

public:
  Token(TokenType type, std::string lexeme, Object literal, int line);

  [[nodiscard]] auto to_string() const -> std::string;
};
#endif // SOLVE_TOKEN_HPP
