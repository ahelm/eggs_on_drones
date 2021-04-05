#include "input.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::tuple<std::string, std::string> dronenav::split_by_space(const std::string& line)
{
  std::string delimitter = " ";
  std::string line_copy = line;
  auto match_str = line_copy.substr(0, line_copy.find(delimitter));
  line_copy.erase(0, line_copy.find(delimitter) + delimitter.length());

  return std::make_tuple(match_str, line_copy);
}

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

std::tuple<int, int, char> dronenav::parse_drone_info(std::string line)
{
  std::string delimitter = " ";

  auto x = std::stoi(line.substr(0, line.find(delimitter)));
  line.erase(0, line.find(delimitter) + delimitter.length());
  auto y = std::stoi(line.substr(0, line.find(" ")));
  line.erase(0, line.find(delimitter) + delimitter.length());
  // take only the first index of matched string -> char representing direction
  auto direction = line.substr(0, line.find(" "))[0];

  return std::make_tuple(x, y, direction);
}
