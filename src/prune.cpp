// License: The Unlicense (https://unlicense.org)
#include <algorithm>
#include <fstream>
#include <iostream>
#include <span>
#include <string>

static constexpr size_t MIN_WORD_LEN = 4;
static constexpr size_t MAX_LETTER_CNT = 7;

auto is_allowed(std::string p_word) {
  auto original_length = p_word.size();
  std::transform(p_word.cbegin(), p_word.cend(), p_word.begin(), [](char p_letter) { return std::toupper(p_letter); });
  std::sort(p_word.begin(), p_word.end());
  auto last = std::unique(p_word.begin(), p_word.end());
  p_word.erase(last, p_word.end());
  return (MIN_WORD_LEN <= original_length) && (p_word.size() <= MAX_LETTER_CNT) &&
         std::all_of(p_word.begin(), p_word.end(), [](char p_letter) { return std::isalpha(p_letter); });
}

auto main(int argc, char* argv[]) -> int {
  auto args = std::span(argv, static_cast<size_t>(argc));
  if (2 > args.size()) {
    // TODO(tybl): Print help
    return -1;
  }
  std::ifstream input(args.back());
  while (input.good()) {
    std::string word;
    input >> word;
    if (is_allowed(word)) {
      std::cout << word << std::endl;
    }
  }
}

// vim: ts=2 sts=2 sw=2 et
