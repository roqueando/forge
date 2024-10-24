#pragma once

#include <argparse/argparse.hpp>
#include <optional>
#include <expected>
#include <memory>

using namespace argparse;

namespace cli
{
  enum class setup_error
  {
    parse_error
  };

  const std::string VERSION = "v1.0";

  const std::string version();
  const std::expected<std::unique_ptr<ArgumentParser>, setup_error> setup(const std::string program_name, int argc, char *argv[]);
};