// License: The Unlicense (https://unlicense.org)
#include "sbee/recommendation_engine.hpp"

#include <algorithm>
#include <ranges>

static constexpr size_t MIN_WORD_LEN = 4;
static constexpr size_t MAX_LETTER_CNT = 7;

void tolower_string(std::string& p_str) {
  std::ranges::transform(p_str, p_str.begin(), [](unsigned char p_ch) { return std::tolower(p_ch); });
}

template <typename CharType>
auto string_contains(std::basic_string<CharType> const& p_str, CharType p_char) {
  return p_str.find(p_char) != std::string::npos;
}

recommendation_engine::recommendation_engine(std::vector<std::string> const& p_word_list)
  : m_word_list() {
  std::copy_if(p_word_list.begin(), p_word_list.end(), std::back_inserter(m_word_list),
               [](std::string const& p_word) -> bool { return is_allowed(p_word); });
  std::for_each(m_word_list.begin(), m_word_list.end(), tolower_string);
}

auto recommendation_engine::get_possibilities(std::string p_required_letters, std::string p_optional_letters)
    -> std::vector<std::string> {

  tolower_string(p_required_letters);
  tolower_string(p_optional_letters);
  p_optional_letters.append(p_required_letters);
  std::ranges::sort(p_optional_letters);
  p_optional_letters.erase(std::unique(p_optional_letters.begin(), p_optional_letters.end()), p_optional_letters.end());

  std::vector<std::string> result(m_word_list);

  result.erase(std::remove_if(result.begin(), result.end(),
                              [p_required_letters](std::string const& p_word) {
                                return !std::ranges::all_of(p_required_letters, [p_word](char p_letter) {
                                  return string_contains(p_word, p_letter);
                                });
                              }),
               result.end());

  p_optional_letters.erase(std::unique(p_optional_letters.begin(), p_optional_letters.end()), p_optional_letters.end());

  result.erase(std::remove_if(result.begin(), result.end(),
                              [p_optional_letters](std::string const& p_word) {
                                return !std::ranges::all_of(p_word, [p_optional_letters](char p_letter) {
                                  return string_contains(p_optional_letters, p_letter);
                                });
                              }),
               result.end());

  return result;
}

// Word length is four or greater
// Letter count is seven or less
// Only contains alphabet characters
auto recommendation_engine::is_allowed(std::string p_word) -> bool {
  auto original_length = p_word.size();

  std::transform(p_word.cbegin(), p_word.cend(), p_word.begin(), [](char p_letter) { return std::tolower(p_letter); });

  std::sort(p_word.begin(), p_word.end());

  p_word.erase(std::unique(p_word.begin(), p_word.end()), p_word.end());

  return (MIN_WORD_LEN <= original_length) && (p_word.size() <= MAX_LETTER_CNT) &&
         std::all_of(p_word.begin(), p_word.end(), [](char p_letter) { return std::isalpha(p_letter); });
}
