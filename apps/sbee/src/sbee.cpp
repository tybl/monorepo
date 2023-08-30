// License: The Unlicense (https://unlicense.org)
// vim:ts=2:sts=2:sw=2:et
#include "sbee/recommendation_engine.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

auto main(int argc, char* argv[]) -> int {
  if (2 > argc) {
    // TODO(tybl): Print help
    return -1;
  }
  std::vector<std::string> word_list;
  std::vector<std::string> correct_word_list;
  std::ifstream input(argv[1]);
  while (input.good()) {
    std::string word;
    input >> word;
    word_list.push_back(word);
  }
  recommendation_engine receng(word_list);

  std::string required_letters;
  std::cout << "What letters must be contained in the word? ";
  std::cin >> required_letters;

  std::string optional_letters;
  std::cout << "What letters may appear in the word? ";
  std::cin >> optional_letters;

  auto recommendations = receng.get_possibilities(required_letters, optional_letters);
  int count = 0;
  for (auto const& word : recommendations) {
    std::cout << (count += 1) << " " << word << std::endl;
  }
}
