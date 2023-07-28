// License: The Unlicense (https://unlicense.org)
// vim:et:ts=2:sw=2

#include "argc++/Application.hpp"

#include <doctest/doctest.h>

#include <stdexcept>

// If '-h' is provided anywhere on the command line,
// argc++ shall throw an exception containing the help message.

// If '--help' is provided anywhere on the command line,
// argc++ shall throw an exception containing the help message.

TEST_CASE("test_help --help") {

  bool caught_exception = false;
  const std::string expected_help_msg =
      "Usage: app [options]\n"
      "\n"
      "Optional arguments:\n"
      "-h, --help, Print this message and exit\n"
      "--version, Print version information and exit\n";
  tybl::argcpp::Application app("app", "1.0.0");

  const int argc = 2;
  SUBCASE("'-h' alone results in help message") {
    const char* argv[] = {"app", "-h", nullptr};
    try {
      app.run(argc, argv);
    } catch (std::runtime_error& err) {
      CHECK_EQ(expected_help_msg, err.what());
      caught_exception = true;
    }
    CHECK(caught_exception);
  } // SUBCASE

  SUBCASE("'--help' alone results in help message") {
    const char* argv[] = {"app", "--help", nullptr};
    try {
      app.run(argc, argv);
    } catch (std::runtime_error& err) {
      CHECK_EQ(expected_help_msg, err.what());
      caught_exception = true;
    }
    CHECK(caught_exception);
  } // SUBCASE
}
