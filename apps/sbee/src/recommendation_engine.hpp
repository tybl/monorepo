// License: The Unlicense (https://unlicense.org)
#pragma once
#include <string>
#include <vector>

void tolower_string(std::string& p_str);

class recommendation_engine {
public:
  explicit recommendation_engine(std::vector<std::string> const& p_word_list);

  auto get_possibilities(std::string p_required_letters, std::string p_optional_letters) -> std::vector<std::string>;

  static auto is_allowed(std::string p_word) -> bool;

private:
  std::vector<std::string> m_word_list;
}; // class WordSearch

