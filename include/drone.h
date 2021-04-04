#pragma once
#include <string>

namespace dronenav
{
  enum Direction
  {
    North,
    West,
    South,
    East
  };

  class Drone
  {
  private:
    int x_;
    int y_;
    Direction direction_;

  public:
    Drone(int x, int y, const char& direction);
    int x();
    int y();
    char direction();
    void turn_left();
    void turn_right();
    void move();
    void process_instruction(const char& instruction);
  };
} // namespace dronenav
