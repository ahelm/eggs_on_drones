#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "input.h"

TEST_CASE("Test spliting of string", "[dronenav::split_by_space]")
{
  auto [match, rest] = dronenav::split_by_space("first_match rest of the string");
  REQUIRE(match == "first_match");
  REQUIRE(rest == "rest of the string");
}

TEST_CASE("Test world size parsing", "[dronenav::parse_world_size]")
{
  auto [width, height] = dronenav::parse_world_size("3 6");
  REQUIRE(width == 3);
  REQUIRE(height == 6);
}

TEST_CASE("Test drone info parsing", "[dronenav::parse_drone_info]")
{
  auto [x, y, direction] = dronenav::parse_drone_info("1 4 W");
  REQUIRE(x == 1);
  REQUIRE(y == 4);
  REQUIRE(direction == 'W');
}
