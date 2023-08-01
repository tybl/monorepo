#include "util/string_contains.hpp"

#include <doctest/doctest.h>

using namespace std::literals;

TEST_CASE("String contains character") { CHECK(tybl::util::string_contains("apples"s, 'a')); }

TEST_CASE("String does not contain character") { CHECK(!tybl::util::string_contains("apples"s, 'b')); }
