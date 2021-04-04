#include "input.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::tuple<int, int> dronenav::parse_world_size(std::string line)
{
  std::string delimitter = " ";

  // find 1st number until first ' ' and convert it to int
  auto width = std::stoi(line.substr(0, line.find(delimitter)));

  // reduce string by removing 1st match
  line.erase(0, line.find(delimitter) + delimitter.length());

  // find 2nd match
  auto height = std::stoi(line.substr(0, line.find(" ")));

  return std::make_tuple(width, height);
}

std::tuple<int, int, std::string> dronenav::parse_drone_info(std::string line)
{
  std::string delimitter = " ";

  auto x = std::stoi(line.substr(0, line.find(delimitter)));
  line.erase(0, line.find(delimitter) + delimitter.length());
  auto y = std::stoi(line.substr(0, line.find(" ")));
  line.erase(0, line.find(delimitter) + delimitter.length());
  auto direction = line.substr(0, line.find(" "));

  return std::make_tuple(x, y, direction);
}
