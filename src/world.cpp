#include "world.h"

dronenav::World::World(int width, int height)
{
  width_ = width;
  height_ = height;
}

int dronenav::World::height()
{
  return height_;
}

int dronenav::World::width()
{
  return width_;
}

std::vector<dronenav::Drone> dronenav::World::drones()
{
  return drones_;
}

void dronenav::World::add_drone(Drone new_drone)
{
  drones_.push_back(new_drone);
}