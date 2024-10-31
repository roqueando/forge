#pragma once

#include <tl/expected.hpp>
#include <memory>
#include <functional>
#include <boost/leaf.hpp>

using namespace tl;

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
    error_on_run_command
  };

  using fail = std::pair<error, std::string>;

  struct command
  {
    std::string name;
    std::vector<std::string_view> args;
    std::function<expected<response, fail>(std::vector<std::string_view>)> action;
  };

  const std::string VERSION = "v1.0";

  const void version();
  const void usage();

  const boost::leaf::result<command> parse(int argc, char *argv[]);

  namespace new_command
  {
    const expected<cli::response, cli::fail> run(std::vector<std::string_view>);
  };
};
