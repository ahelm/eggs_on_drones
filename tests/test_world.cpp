#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "world.h"

TEST_CASE("Test world creation", "[dronenav::World]")
{
  dronenav::World some_world{5, 6};
  REQUIRE(some_world.width() == 5);
  REQUIRE(some_world.height() == 6);
  REQUIRE(some_world.drones().empty());
}
