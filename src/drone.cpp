#include "drone.h"
#include <exception>

dronenav::Drone::Drone(int x, int y, std::string direction)
{
  x_ = x;
  y_ = y;

  if (direction == "N")
    direction_ = dronenav::Direction::North;
  else if (direction == "S")
    direction_ = dronenav::Direction::South;
  else if (direction == "E")
    direction_ = dronenav::Direction::East;
  else if (direction == "W")
    direction_ = dronenav::Direction::West;
  else
    throw std::invalid_argument("Direction has to be a 'N', 'S', 'E', or 'W'");
};

int dronenav::Drone::x()
{
  return this->x_;
}

int dronenav::Drone::y()
{
  return this->y_;
}

std::string dronenav::Drone::direction()
{
  switch (this->direction_)
  {
  case North:
    return "N";
  case South:
    return "S";
  case West:
    return "W";
  case East:
    return "E";
  }
}