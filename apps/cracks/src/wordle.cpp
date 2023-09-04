// License: The Unlicense (https://unlicense.org)
// vim:ts=2:sts=2:sw=2:et
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::map<char, float> letter_freq {
  {'a',0.07'8},
  {'b',0.02'0},
  {'c',0.04'0},
  {'d',0.03'8},
  {'e',0.11'0},
  {'f',0.01'4},
  {'g',0.03'0},
  {'h',0.02'3},
  {'i',0.08'6},
  {'j',0.00'21},
  {'k',0.00'97},
  {'l',0.05'3},
  {'m',0.02'7},
  {'n',0.07'2},
  {'o',0.06'1},
  {'p',0.02'8},
  {'q',0.00'19},
  {'r',0.07'3},
  {'s',0.08'7},
  {'t',0.06'7},
  {'u',0.03'3},
  {'v',0.01'0},
  {'w',0.00'91},
  {'x',0.00'27},
  {'y',0.01'6},
  {'z',0.00'44}
};

struct word {

  word(std::string_view p_word);

  float value() const;

private:

  void add_letter(char p_letter);

  bool has_letter(char p_letter) const;

  uint32_t m_letters = 0;
};

word::word(std::string_view p_word) {
  for (auto ch : p_word) {
    add_letter(ch);
  }
}

float word::value() const {
  float result = 0.0;
  for (auto const& ch : letter_freq) {
    result += has_letter(ch.first) ? ch.second : 0.0f;
  }
  return result;
}

void word::add_letter(char p_letter) {
  if (std::isalpha(p_letter)) {
    m_letters |= static_cast<uint32_t>(1 << (std::tolower(p_letter) - 'a'));
  }
}

bool word::has_letter(char p_letter) const {
  return std::isalpha(p_letter) && (m_letters & static_cast<uint32_t>(1 << (std::tolower(p_letter) - 'a')));
}

auto main(int argc, char* argv[]) -> int {
  if (2 > argc) {
    // TODO(tybl): Print help
    return -1;
  }
  std::ifstream input(argv[1]);
  std::string best_word;
  float best_value = 0.0f;
  while (input.good()) {
    std::string wrd;
    input >> wrd;
    if (5 == wrd.length()) {
      word possibility(wrd);
      auto my_value = possibility.value();
      if (my_value > best_value) {
        best_value = my_value;
        best_word = wrd;
      }
    }
  }
  std::cout << best_word << std::endl;
}
