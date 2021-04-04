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

TEST_CASE("Test drone turning left", "[dronenav::Drone::turn_left]")
{
  SECTION("Check: North -> West")
  {
    dronenav::Drone drone{0, 1, "N"};
    drone.turn_left();
    REQUIRE(drone.direction() == "W");
  }

  SECTION("Check: West -> South")
  {
    dronenav::Drone drone{0, 1, "W"};
    drone.turn_left();
    REQUIRE(drone.direction() == "S");
  }

  SECTION("Check: South -> East")
  {
    dronenav::Drone drone{0, 1, "S"};
    drone.turn_left();
    REQUIRE(drone.direction() == "E");
  }

  SECTION("Check: East -> North")
  {
    dronenav::Drone drone{0, 1, "E"};
    drone.turn_left();
    REQUIRE(drone.direction() == "N");
  }
}

TEST_CASE("Test drone turning right", "[dronenav::Drone::turn_right]")
{
  SECTION("Check: North -> East")
  {
    dronenav::Drone drone{0, 1, "N"};
    drone.turn_right();
    REQUIRE(drone.direction() == "E");
  }

  SECTION("Check: East -> South")
  {
    dronenav::Drone drone{0, 1, "E"};
    drone.turn_right();
    REQUIRE(drone.direction() == "S");
  }

  SECTION("Check: South -> West")
  {
    dronenav::Drone drone{0, 1, "S"};
    drone.turn_right();
    REQUIRE(drone.direction() == "W");
  }

  SECTION("Check: West -> North")
  {
    dronenav::Drone drone{0, 1, "W"};
    drone.turn_right();
    REQUIRE(drone.direction() == "N");
  }
}

TEST_CASE("Test drone moving", "[dronenav::Drone::move]")
{
  SECTION("Check: facing north")
  {
    dronenav::Drone drone{2, 2, "N"};
    drone.move();
    REQUIRE(drone.x() == 2);
    REQUIRE(drone.y() == 3);
  }

  SECTION("Check: facing south")
  {
    dronenav::Drone drone{2, 2, "S"};
    drone.move();
    REQUIRE(drone.x() == 2);
    REQUIRE(drone.y() == 1);
  }

  SECTION("Check: facing west")
  {
    dronenav::Drone drone{2, 2, "W"};
    drone.move();
    REQUIRE(drone.x() == 1);
    REQUIRE(drone.y() == 2);
  }

  SECTION("Check: facing east")
  {
    dronenav::Drone drone{2, 2, "E"};
    drone.move();
    REQUIRE(drone.x() == 3);
    REQUIRE(drone.y() == 2);
  }
}
