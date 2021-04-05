#include <string>
#include <iostream>

#include "drone.h"
#include "world.h"
#include "input.h"

int main()
{
  try
  {
    std::string world_size_str;
    std::getline(std::cin, world_size_str);
    auto [world_width, world_height] = dronenav::parse_world_size(world_size_str);
    dronenav::World world{world_width, world_height};

    std::string line;
    while (true)
    {
      std::getline(std::cin, line);
      if (line.empty())
        break;

      try
      {
        auto [x, y, direction] = dronenav::parse_drone_info(line);
        dronenav::Drone new_drone{x, y, direction};

        std::getline(std::cin, line);
        for (const auto &c : line)
          new_drone.process_instruction(c);
        world.add_drone(new_drone);
      }
      catch (const std::exception &e)
      {
        std::cerr << "[ERROR] During processing of drone information" << '\n';
        std::cerr << "[ERROR] " << e.what() << '\n';
        exit(2);
      }
    }

    for (auto drone : world.drones())
      std::cout << drone.x() << " " << drone.y() << " " << drone.direction() << '\n';
  }
  catch (const std::exception &e)
  {
    std::cerr << "[ERROR] During processing of world information" << '\n';
    std::cerr << "[ERROR] " << e.what() << '\n';
    exit(1);
  }
}
