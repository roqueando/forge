#pragma once

#include <argparse/argparse.hpp>
#include <tl/expected.hpp>
#include <memory>
#include <functional>

using namespace argparse;
using namespace tl;

namespace cli
{
  enum class error
  {
    parse_error,
    command_error
  };

  enum class response
  {
    ok,
    error_on_run_command
  };

  using fail = std::pair<error, std::exception&>;

  struct command
  {
    std::string name;
    std::vector<std::string_view> args;
    std::function<expected<response, fail>(std::vector<std::string_view>)> action;
  };

  const std::string VERSION = "v1.0";

  const void version();

  const expected<std::shared_ptr<ArgumentParser>, error> setup(const std::string program_name, int argc, char *argv[]);

  const expected<response, error> run(std::shared_ptr<ArgumentParser> program);
  const command parse(int argc, char *argv[]);
};
