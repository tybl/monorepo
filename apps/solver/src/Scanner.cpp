#include "Scanner.hpp"

scanner::scanner(std::string p_source)
  : m_source(std::move(p_source)) {}

std::vector<token> scanner::scan_tokens() {
  while (!is_at_end()) {
    m_start = m_current;
    scan_token();
  }
  m_tokens.emplace_back(TokenType::END_OF_FILE, "", Object(), m_line);
  return m_tokens;
}

void scanner::add_token(TokenType p_type) { add_token(p_type, Object()); }

void scanner::add_token(TokenType p_type, Object p_literal) {
  std::string text = m_source.substr(m_start, m_current);
  m_tokens.emplace_back(p_type, text, p_literal, m_line);
}

char scanner::advance() { return m_source.at(m_current++); }

[[nodiscard]] bool scanner::is_at_end() const { return m_source.length() <= m_current; }

void scanner::scan_token() {
  char c = advance();
  switch (c) {
    using enum TokenType;
    case '(': add_token(LEFT_PAREN); break;
    case ')': add_token(RIGHT_PAREN); break;
    case '{': add_token(LEFT_BRACE); break;
    case '}': add_token(RIGHT_BRACE); break;
    case ',': add_token(COMMA); break;
    case '.': add_token(DOT); break;
    case '-': add_token(MINUS); break;
    case '+': add_token(PLUS); break;
    case ';': add_token(SEMICOLON); break;
    case '*': add_token(STAR); break;
    case '!': add_token(match('=') ? BANG_EQUAL : BANG); break;
    case '=': add_token(match('=') ? EQUAL_EQUAL : EQUAL); break;
    case '<': add_token(match('=') ? LESS_EQUAL : LESS); break;
    case '>': add_token(match('=') ? GREATER_EQUAL : GREATER); break;
    case '/':
      if (match('/')) {
        while (peek() != '\n' && !is_at_end())
          advance();
      } else {
        add_token(SLASH);
      }
      break;
    case ' ':
    case '\r':
    case '\t': break;
    case '\n': m_line++; break;
    default: break;
  }
}

bool scanner::match(char p_expected) {
  if (is_at_end())
    return false;
  if (m_source.at(m_current) != p_expected)
    return false;
  m_current++;
  return true;
}

char scanner::peek() {
  if (is_at_end())
    return '\0';
  return m_source.at(m_current);
}
