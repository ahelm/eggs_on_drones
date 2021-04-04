#pragma once
#include <vector>
#include "drone.h"

namespace dronenav
{
  class World
  {
  private:
    int width_;
    int height_;
    std::vector<Drone> drones_;
  public:
    World(int width, int height);
    int width();
    int height();
    std::vector<Drone> drones();
    void add_drone(Drone new_drone);
  };
} // namespace dronenav
