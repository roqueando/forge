#pragma once

#include <boost/leaf.hpp>
#include <forge/cli.hpp>
#include <filesystem>

namespace leaf = boost::leaf;
namespace fs = std::filesystem;

namespace new_command
{
  const void usage();
  const leaf::result<int> run(std::vector<std::string_view>);
  const fs::path generate_path(std::string, std::string);
};
