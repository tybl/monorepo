// License: The Unlicense (https://unlicense.org)
#include "cli/Command.hpp"

#include "doctest/doctest.h"

#include <cstdlib>
#include <ctime>
#include <string_view>
#include <vector>

TEST_CASE("tasklib/cli/Command") {
  // Setup
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  int result = rand();
  //  Command
  ogre::command cmd("git");
  cmd.add_action([result](ogre::parameters const& /*args*/) -> int { return result; });
  //  Input
  std::vector<std::string_view> input{"git"};

  // Execute
  CHECK(result == cmd.run(input));
}

TEST_CASE("tasklib/cli/Command subcommand") {
  // Setup
  int result = rand();
  //  Command
  ogre::command cmd("git");
  auto& add = cmd.add_subcommand("add");
  add.add_action([result](ogre::parameters const& p_args) -> int {
    CHECK(p_args.arguments.front() == "main.cpp");
    return result;
  });
  //  Input
  std::vector<std::string_view> input{"git", "add", "main.cpp"};

  // Execute
  CHECK(result == cmd.run(input));
}

TEST_CASE("tasklib/cli/Command option") {
  // Setup
  int result = rand();
  //  Command
  ogre::command cmd("git");
  auto& rm = cmd.add_subcommand("rm");
  rm.add_option("-f", "--force").add_help("Override the up-to-date check.");
  rm.add_option("-r").add_help("Allow recursive removal when leading directory name is given.");
  rm.add_action([result](ogre::parameters const& p_args) -> int {
    REQUIRE(p_args.options.contains("-f"));
    CHECK(p_args.options.at("-f") == "true");
    REQUIRE(p_args.options.contains("--force"));
    CHECK(p_args.options.at("--force") == "true");
    CHECK(!p_args.options.contains("-r"));
    CHECK(p_args.arguments.front() == "main.cpp");
    return result;
  });
  //  Input
  std::vector<std::string_view> input{"git", "rm", "-f", "main.cpp"};

  // Execute
  CHECK(result == cmd.run(input));
}
