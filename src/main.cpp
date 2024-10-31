#include <boost/leaf/handle_errors.hpp>
#include <forge/cli.hpp>
#include <iostream>

namespace leaf = boost::leaf;

int main(int argc, char *argv[]) {
  return leaf::try_handle_some(
             [&]() -> leaf::result<int> {
               auto cmd = cli::parse(argc, argv);
               std::cout << cmd.value().name << std::endl;
               return 0;
             },
             [](leaf::match<cli::error, cli::error::command_not_found>)
                 -> leaf::result<int> {
               std::cerr << "command not found" << std::endl;
               cli::usage();
               return -1;
             },

             [](leaf::match<cli::error, cli::error::not_enough_commands>)
                 -> leaf::result<int> {
               std::cerr << "not enough commands" << std::endl;
               cli::usage();
               return -1;
             })
      .value();
}
