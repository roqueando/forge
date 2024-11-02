#include <boost/leaf/handle_errors.hpp>
#include <cstdlib>
#include <forge/cli.hpp>
#include <forge/new_command.hpp>
#include <forge/templates.hpp>
#include <iostream>

namespace leaf = boost::leaf;

int main(int argc, char *argv[]) {
  return leaf::try_handle_some(
    [&]() -> leaf::result<int> {
      auto cmd = cli::parse(argc, argv).value();
      return cmd.action(cmd.args);
    },

    [](leaf::match<templates::error, templates::error::project_name_required>)
    -> leaf::result<int> {
      std::cerr << "project name is required!" << std::endl;
      new_command::usage();
      return EXIT_FAILURE;
    },
    
    [](leaf::match<templates::error, templates::error::directory_exists>)
    -> leaf::result<int> {
      std::cerr << "directory already exists!" << std::endl;
      new_command::usage();
      return EXIT_FAILURE;
    },

    [](leaf::match<cli::error, cli::error::command_not_found>)
    -> leaf::result<int> {
      std::cerr << "command not found" << std::endl;
      cli::usage();
      return EXIT_FAILURE;
    },

    [](leaf::match<cli::error, cli::error::not_enough_commands>)
    -> leaf::result<int> {
      std::cerr << "not enough commands" << std::endl;
      cli::usage();
      return EXIT_FAILURE;
    })
  .value();
}
