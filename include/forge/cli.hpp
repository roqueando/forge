#pragma once

#include <boost/leaf.hpp>

namespace leaf = boost::leaf;

namespace cli
{
  enum class error
  {
    parse_error,
    not_enough_commands,
    command_not_found,
    command_error
  };

  enum class response
  {
    ok,
    parse_error,
    not_enough_commands,
    command_not_found,
    command_error 
  };

  struct command
  {
    std::string name;
    std::vector<std::string_view> args;
    std::function<leaf::result<int>(std::vector<std::string_view>)> action;
  };

  const std::string VERSION = "v1.0";

  const void version();
  const void usage();

  const boost::leaf::result<command> parse(int argc, char *argv[]);
};
