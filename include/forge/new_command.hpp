#pragma once

#include <boost/leaf.hpp>
#include <forge/cli.hpp>

namespace leaf = boost::leaf;

namespace new_command
{
enum class error
{
  project_name_required,
  directory_exists
};

const void usage();
const leaf::result<int> run(std::vector<std::string_view>);
};
