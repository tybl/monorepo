#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

static constexpr size_t MIN_WORD_LEN = 4;
static constexpr size_t MAX_LETTER_CNT = 7;

class recommendation_engine {
public:
  explicit recommendation_engine(std::vector<std::string> const& p_word_list) {
    std::copy_if(p_word_list.begin(), p_word_list.end(), std::back_inserter(m_word_list), [](std::string const& p_word) -> bool { return is_allowed(p_word); });
    std::for_each(m_word_list.begin(), m_word_list.end(), [](std::string& p_word){ std::transform(p_word.begin(), p_word.end(), p_word.begin(), [](char p_letter){ return std::tolower(p_letter); }); });
  }

  auto get_possibilities(char p_required_letter, std::string p_optional_letters) -> std::vector<std::string> {
    p_required_letter = static_cast<char>(std::tolower(p_required_letter));
    std::vector<std::string> result(m_word_list);
    result.erase(std::remove_if(result.begin(), result.end(), [p_required_letter](std::string const& p_word){ return p_word.find(p_required_letter) == std::string::npos; }), result.end());
    p_optional_letters.push_back(p_required_letter);
    std::transform(p_optional_letters.begin(), p_optional_letters.end(), p_optional_letters.begin(), [](char p_letter){ return std::tolower(p_letter); });
    std::sort(p_optional_letters.begin(), p_optional_letters.end());
    p_optional_letters.erase(std::unique(p_optional_letters.begin(), p_optional_letters.end()), p_optional_letters.end());
    result.erase(std::remove_if(result.begin(),
                                result.end(),
                                [p_optional_letters](std::string const& p_word){
      return std::any_of(p_word.begin(),
                         p_word.end(),
                         [p_optional_letters](char p_letter){
        return p_optional_letters.find(p_letter) == std::string::npos;
      });
    }), result.end());
    return result;
  }

  static auto is_allowed(std::string p_word) -> bool {
    auto original_length = p_word.size();
    std::transform(p_word.cbegin(), p_word.cend(), p_word.begin(), [](char p_letter){ return std::tolower(p_letter); });
    std::sort(p_word.begin(), p_word.end());
    p_word.erase(std::unique(p_word.begin(), p_word.end()), p_word.end());
    return (MIN_WORD_LEN <= original_length) && (p_word.size() <= MAX_LETTER_CNT) && std::all_of(p_word.begin(), p_word.end(), [](char p_letter){ return std::isalpha(p_letter); });
  }

private:
  std::vector<std::string> m_word_list;
}; // class WordSearch

auto main(int argc, char* argv[]) -> int {
  if (2 > argc) {
    // TODO(tybl): Print help
    return -1;
  }
  std::vector<std::string> word_list;
  std::ifstream input(argv[1]);
  while (input.good()) {
    std::string word;
    input >> word;
    word_list.push_back(word);
  }
  char required_letter = '\0';
  std::string optional_letters;
  recommendation_engine receng(word_list);
  std::cout << "What letter must be contained in the word? ";
  std::cin >> required_letter;
  std::cout << "What letters may appear in the word? ";
  std::cin >> optional_letters;
  auto recommendations = receng.get_possibilities(required_letter, optional_letters);
  for (auto const& word : recommendations) {
    std::cout << word << std::endl;
  }
}

// vim: ts=2 sts=2 sw=2 et
