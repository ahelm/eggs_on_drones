#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "drone.h"
#include <exception>

TEST_CASE("Test drone creation", "[dronenav::Drone]")
{
  dronenav::Drone some_drone{0, 1, "N"};
  REQUIRE(some_drone.x() == 0);
  REQUIRE(some_drone.y() == 1);
  REQUIRE(some_drone.direction() == "N");
}

TEST_CASE("Test drone directions", "[dronenav::Drone::direction]")
{
  dronenav::Drone done1{0, 1, "N"};
  REQUIRE(done1.direction() == "N");

  dronenav::Drone drone2{0, 1, "S"};
  REQUIRE(drone2.direction() == "S");

  dronenav::Drone drone3{0, 1, "E"};
  REQUIRE(drone3.direction() == "E");

  dronenav::Drone drone4{0, 1, "W"};
  REQUIRE(drone4.direction() == "W");
}
