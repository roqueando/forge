#include <iostream>
#include <rawr/cli.hpp>

int main(int argc, char *argv[])
{
  // TODO: setup argparse
  if (const auto program = cli::setup("rawr", argc, argv); program.has_value()) {
    std::cout << "nice!" << std::endl;
  } else if(program.error() == cli::setup_error::parse_error) {
    std::cout << "something has wrong" << std::endl;
  }
  return 0;
}
