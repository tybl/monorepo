#include <bit>
#include <fstream>
#include <iostream>

auto alphabet_index(char letter) -> size_t {
  return std::toupper(letter) - 'A';
}

auto main(int argc, char* argv[]) -> int {
  if (2 > argc) {
    // TODO(tybl): Print help
    return -1;
  }
  std::ifstream input(argv[1]);
  while (input.good()) {
    uint32_t found_letters = 0;
    std::string word;
    input >> word;
    for (auto letter : word) {
      if (isalpha(letter)) {
        found_letters |= 1 << alphabet_index(letter);
      }
    }
    std::cout << word << " " << std::popcount(found_letters) << std::endl;
  }
}

// vim: ts=2 sts=2 sw=2 et
