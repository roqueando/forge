#include <iostream>
#include <optional>
#include <rawr/cli.hpp>
#include <argparse/argparse.hpp>
#include <expected>
#include <memory>

using namespace argparse;

const std::string cli::version()
{
  return cli::VERSION;
}

const std::expected<std::unique_ptr<ArgumentParser>, cli::setup_error> cli::setup(const std::string program_name, int argc, char *argv[])
{
  std::unique_ptr<ArgumentParser> program = std::make_unique<ArgumentParser>(program_name);

  program->add_argument("-v", "--version")
      .help("display rawr version")
      .flag();

  try
  {
    program->parse_args(argc, argv);
    return program;
  }
  catch (std::exception &err)
  {
    return std::unexpected(cli::setup_error::parse_error);
  }
}
