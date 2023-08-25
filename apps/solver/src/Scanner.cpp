#include "Scanner.hpp"

Scanner::Scanner(std::string source)
  : m_source(std::move(source)) {}

std::vector<Token> Scanner::scan_tokens() {
  while (!is_at_end()) {
    start = current;
    scan_token();
  }
  tokens.emplace_back(TokenType::END_OF_FILE, "", Object(), line);
  return tokens;
}

void Scanner::add_token(TokenType type) { add_token(type, Object()); }

void Scanner::add_token(TokenType type, Object literal) {
  std::string text = m_source.substr(start, current);
  tokens.emplace_back(type, text, literal, line);
}

char Scanner::advance() { return m_source.at(current++); }

[[nodiscard]] bool Scanner::is_at_end() const { return m_source.length() <= current; }

void Scanner::scan_token() {
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
    case '\n': line++; break;
    default: break;
  }
}

bool Scanner::match(char expected) {
  if (is_at_end())
    return false;
  if (m_source.at(current) != expected)
    return false;
  current++;
  return true;
}

char Scanner::peek() {
  if (is_at_end())
    return '\0';
  return m_source.at(current);
}
