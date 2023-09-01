// License: The Unlicense (https://unlicense.org)
#include "stacks/stack_state.hpp"
#include "stacks/board.hpp"

#include <doctest/doctest.h>

#include <sstream>

TEST_CASE("Board") {
  std::istringstream input(
      "12300\n"
      "12300\n"
      "12300\n"
      "12300\n");
  Board b(input);
  edge e{0, 3};
  CHECK(!b.is_valid(e));
  auto steps = b.generate_steps();
  CHECK(steps.size() == 0UL);
}
