#include <iostream>
#include <forge/cli.hpp>

int main(int argc, char *argv[])
{
  const auto command = cli::parse(argc, argv);
  std::cout << command.name << "\n";
  return 0;
}

