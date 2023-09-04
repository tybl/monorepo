// License: The Unlicense (https://unlicense.org)
// vim:et:ts=2:sw=2

#include "argc++/Application.hpp"

#include <doctest/doctest.h>

#include <stdexcept>

// If '--version' is provided anywhere on the command line,
// argc++ shall throw an exception containing the help message.

TEST_CASE("test_help --version") {

  bool caught_exception = false;
  const std::string expected_msg = "app version 1.0.0";
  tybl::argcpp::application app("app", "1.0.0");

  int const argc = 2;
  char const* argv[] = {"app", "--version", nullptr};
  try {
    app.run(argc, argv);
  } catch (std::runtime_error& err) {
    CHECK_EQ(expected_msg, err.what());
    caught_exception = true;
  }
  CHECK(caught_exception);
}
