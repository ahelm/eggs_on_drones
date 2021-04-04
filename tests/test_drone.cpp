#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "drone.h"

TEST_CASE("Test drone creation", "[dronenav::Drone]")
{
  dronenav::Drone some_drone{0, 1, "N"};
  REQUIRE(some_drone.x() == 0);
  REQUIRE(some_drone.y() == 1);
  REQUIRE(some_drone.direction() == "N");
}
