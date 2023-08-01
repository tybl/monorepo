#pragma once
#include <string>
#include <vector>

class recommendation_engine {
public:
  explicit recommendation_engine(std::vector<std::string> const& p_word_list);

  auto get_possibilities(char p_required_letter, std::string p_optional_letters) -> std::vector<std::string>;

  static auto is_allowed(std::string p_word) -> bool;

private:
  std::vector<std::string> m_word_list;
}; // class WordSearch

