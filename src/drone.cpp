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
  return x_;
}

int dronenav::Drone::y()
{
  return y_;
}

std::string dronenav::Drone::direction()
{
  switch (direction_)
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

void dronenav::Drone::turn_left()
{
  switch (direction_)
  {
  case North:
    direction_ = dronenav::Direction::West;
    break;
  case South:
    direction_ = dronenav::Direction::East;
    break;
  case West:
    direction_ = dronenav::Direction::South;
    break;
  case East:
    direction_ = dronenav::Direction::North;
    break;
  }
}

void dronenav::Drone::turn_right()
{
  switch (direction_)
  {
  case North:
    direction_ = dronenav::Direction::East;
    break;
  case South:
    direction_ = dronenav::Direction::West;
    break;
  case West:
    direction_ = dronenav::Direction::North;
    break;
  case East:
    direction_ = dronenav::Direction::South;
    break;
  }
}

void dronenav::Drone::move()
{
  switch (direction_)
  {
  case North:
    y_++;
    break;
  case South:
    y_--;
    break;
  case West:
    x_--;
    break;
  case East:
    x_++;
    break;
  }
}

void dronenav::Drone::process_instruction(const std::string &instruction)
{
  if (instruction == "L")
    turn_left();
  else if (instruction == "R")
    turn_right();
  else if (instruction == "M")
    move();
  else
    throw std::invalid_argument("Instruction has to be 'L', 'R', or 'M'");
}