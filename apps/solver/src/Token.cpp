//
// Created by tybl on 1/5/23.
//

#include "Token.hpp"

token::token(TokenType p_type, std::string p_lexeme, Object p_literal, int p_line)
  : m_type(p_type)
  , m_lexeme(std::move(p_lexeme))
  , m_literal(p_literal)
  , m_line(p_line) {}

[[nodiscard]] auto token::to_string() const -> std::string { return m_lexeme; }
