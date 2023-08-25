//
// Created by tybl on 1/5/23.
//

#include "Token.hpp"

Token::Token(TokenType type, std::string lexeme, Object literal, int line)
  : type(type)
  , lexeme(std::move(lexeme))
  , literal(literal)
  , line(line) {}

[[nodiscard]] auto Token::to_string() const -> std::string { return lexeme; }
