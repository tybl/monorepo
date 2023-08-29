#include "Object.hpp"
#include "Scanner.hpp"
#include "Solve.hpp"
#include "Token.hpp"
#include "TokenType.hpp"

#include <fstream>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

int main(int argc, char* argv[]) {
  solve solver;
  if (2 < argc) {
    return -1;
  } else if (2 == argc) {
    solver.run_file(argv[1]);
  } else if (1 == argc) {
    solver.run_prompt();
  }
  return 0;
}
