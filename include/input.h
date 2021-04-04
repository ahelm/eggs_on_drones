#pragma once
#include <tuple>
#include <string>

namespace dronenav
{
  std::tuple<int, int> parse_world_size(std::string line);
  std::tuple<int, int, char> parse_drone_info(std::string line);
} // namespace dronenav
