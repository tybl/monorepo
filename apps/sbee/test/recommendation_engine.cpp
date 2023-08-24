// License: The Unlicense (https://unlicense.org)
#include "recommendation_engine.hpp"

#include <doctest/doctest.h>

TEST_CASE("tolower_string") {
   std::string unknown_case = "tHIs iS MY sTRinG";
   std::string lowered_case = "this is my string";
   tolower_string(unknown_case);
   CHECK_EQ(unknown_case, lowered_case);
}

TEST_CASE("rec_eng") {
   recommendation_engine rex({"alice", "bob", "string", "buffer", "resource", "abcdefgh"});
   auto answers = rex.get_possibilities("l", "aice");
   CHECK(1 == answers.size());
   answers = rex.get_possibilities("al", "ice");
   CHECK(1 == answers.size());
   answers = rex.get_possibilities("alice", "ice");
   CHECK(1 == answers.size());
   answers = rex.get_possibilities("ln", "aice");
   CHECK(0 == answers.size());
   answers = rex.get_possibilities("bcdefgh", "");
   CHECK(0 == answers.size()); // "abcdefgh" should have been stripped from inputs
}

TEST_CASE("2023-08-01") {
   recommendation_engine rex({ "armour", "around", "arum", "aunt", "aura", "aurora", "clue", "clued", "cuddle", "cuddled", "cued", "cull", "culled", "deduce", "deduced", "delude"});
   auto answers = rex.get_possibilities("u", "indlce");
   CHECK(10 == answers.size());
}