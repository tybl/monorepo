#include "recommendation_engine.hpp"

#include <algorithm>

static constexpr size_t MIN_WORD_LEN = 4;
static constexpr size_t MAX_LETTER_CNT = 7;

recommendation_engine::recommendation_engine(std::vector<std::string> const& p_word_list) {
  std::copy_if(p_word_list.begin(), p_word_list.end(), std::back_inserter(m_word_list),
               [](std::string const& p_word) -> bool { return is_allowed(p_word); });
  std::for_each(m_word_list.begin(), m_word_list.end(), [](std::string& p_word) {
    std::transform(p_word.begin(), p_word.end(), p_word.begin(),
                   [](char p_letter) { return std::tolower(p_letter); });
  });
}

auto recommendation_engine::get_possibilities(char p_required_letter, std::string p_optional_letters) -> std::vector<std::string> {

  p_required_letter = static_cast<char>(std::tolower(p_required_letter));

  std::vector<std::string> result(m_word_list);

#ifdef __cpp_lib_string_contains
#warning "Replace 'p_word.find(p_required_letter) == std::string::npos' with 'p_word.contains(p_required_letter)'"
#endif
  result.erase(std::remove_if(result.begin(), result.end(),
                              [p_required_letter](std::string const& p_word) {
                                return p_word.find(p_required_letter) == std::string::npos;
                              }),
               result.end());

  p_optional_letters.push_back(p_required_letter);

  std::transform(p_optional_letters.begin(), p_optional_letters.end(), p_optional_letters.begin(),
                 [](char p_letter) { return std::tolower(p_letter); });

  std::sort(p_optional_letters.begin(), p_optional_letters.end());

  p_optional_letters.erase(std::unique(p_optional_letters.begin(), p_optional_letters.end()),
                           p_optional_letters.end());

  result.erase(std::remove_if(result.begin(), result.end(),
                              [p_optional_letters](std::string const& p_word) {
                                return std::any_of(p_word.begin(), p_word.end(), [p_optional_letters](char p_letter) {
#ifdef __cpp_lib_string_contains
#warning "Replace 'p_optional_letters.find(p_letter) == std::string::npos' with 'p_optional_letters.contains(p_letter)'"
#endif
                                  return p_optional_letters.find(p_letter) == std::string::npos;
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

  std::transform(p_word.cbegin(), p_word.cend(), p_word.begin(),
                 [](char p_letter) { return std::tolower(p_letter); });

  std::sort(p_word.begin(), p_word.end());

  p_word.erase(std::unique(p_word.begin(), p_word.end()), p_word.end());

  return (MIN_WORD_LEN <= original_length) && (p_word.size() <= MAX_LETTER_CNT) &&
         std::all_of(p_word.begin(), p_word.end(), [](char p_letter) { return std::isalpha(p_letter); });
}
