#include "input.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::tuple<std::string, std::string> dronenav::split_by_space(const std::string &line)
{
  std::string delimitter = " ";
  std::string line_copy = line;
  auto match_str = line_copy.substr(0, line_copy.find(delimitter));
  line_copy.erase(0, line_copy.find(delimitter) + delimitter.length());

  return std::make_tuple(match_str, line_copy);
}

std::tuple<int, int> dronenav::parse_world_size(std::string line)
{
  auto [width_str, rest] = dronenav::split_by_space(line);
  auto [height_str, _] = dronenav::split_by_space(rest);

  auto width = std::stoi(width_str);
  auto height = std::stoi(height_str);

  return std::make_tuple(width, height);
}

std::tuple<int, int, char> dronenav::parse_drone_info(std::string line)
{
  auto [x_str, rest_without_x] = dronenav::split_by_space(line);
  auto [y_str, rest] = dronenav::split_by_space(rest_without_x);
  auto [direction_str, _] = dronenav::split_by_space(rest);

  auto x = std::stoi(x_str);
  auto y = std::stoi(y_str);
  auto direction = direction_str[0];

  return std::make_tuple(x, y, direction);
}
