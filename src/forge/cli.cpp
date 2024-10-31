#include <iostream>
#include <boost/leaf.hpp>
#include <boost/leaf/error.hpp>
#include <boost/leaf/result.hpp>
#include <forge/new_command.hpp>
#include <forge/cli.hpp>

namespace leaf = boost::leaf;

const void cli::version() { std::cout << cli::VERSION << "\n"; }
const void cli::usage() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "forge [" << cli::VERSION
            << "] a tool for generate modern C++ projects" << std::endl;
  std::cout << "-----------------------USAGE--------------------------"
            << std::endl;

  std::cout
      << "#> new <project_name> - generate a new project in the current folder"
      << std::endl;
}

const leaf::result<cli::command> cli::parse(int argc, char *argv[]) {
  if (argc == 1) {
    return leaf::new_error(cli::error::not_enough_commands);
  }

  std::vector<std::string_view> args(argv + 1, argv + argc);
  std::vector<std::string_view> command_args(argv + 2, argv + argc);

  if (args.at(0) == "new") {
    return cli::command{"new", command_args, new_command::run};
  }

  return leaf::new_error(cli::error::command_not_found);
}
