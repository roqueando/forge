#include <iostream>
#include <forge/new_command.hpp>
#include <forge/cli.hpp>


const void new_command::usage()
{
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "forge [" << cli::VERSION
    << "] #new" << std::endl;
  std::cout << "-----------------------USAGE--------------------------"
    << std::endl;

  std::cout
    << "#> <project_name> [required] - generate a new project in the current folder"
    << std::endl;
}

const leaf::result<int> new_command::run(std::vector<std::string_view> args) {
  return leaf::new_error(new_command::error::project_name_required);
}
