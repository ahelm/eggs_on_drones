#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "input.h"

TEST_CASE("Test world size parsing", "[dronenav::parse_world_size]")
{
  auto [width, height] = dronenav::parse_world_size("3 6");
  REQUIRE(width == 3);
  REQUIRE(height == 6);
}

