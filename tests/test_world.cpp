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

TEST_CASE("Test add drone to world", "[dronenav::World::add_drone]")
{
  dronenav::World some_world{5, 10};
  dronenav::Drone some_drone{3, 6, 'W'};

  some_world.add_drone(some_drone);

  auto stored_drone = some_world.drones()[0];
  REQUIRE(stored_drone.x() == 3);
  REQUIRE(stored_drone.y() == 6);
  REQUIRE(stored_drone.direction() == 'W');
}