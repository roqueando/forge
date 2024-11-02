#pragma once

#include <boost/leaf.hpp>
#include <forge/cli.hpp>

namespace leaf = boost::leaf;

namespace new_command
{
  const void usage();
  const leaf::result<int> run(std::vector<std::string_view>);
};
