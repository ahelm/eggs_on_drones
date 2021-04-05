#pragma once
#include <tuple>
#include <string>

namespace dronenav
{
  std::tuple<std::string, std::string> split_by_space(const std::string& line);
  std::tuple<int, int> parse_world_size(const std::string& line);
  std::tuple<int, int, char> parse_drone_info(const std::string& line);
} // namespace dronenav
