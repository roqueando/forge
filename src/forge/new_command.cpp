#include <boost/leaf/error.hpp>
#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <forge/new_command.hpp>
#include <forge/cli.hpp>
#include <forge/templates.hpp>

namespace fs = std::filesystem;
namespace leaf = boost::leaf;

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

const leaf::result<int> create_project_folder(std::string project_name)
{
  const fs::path template_path = "templates/base";
  const fs::path destination = fs::current_path()
    .concat("/")
    .concat(project_name.begin(), project_name.end());
  if (!fs::exists(destination)) {
    fs::create_directory(destination);
    return EXIT_SUCCESS;
  }

  return leaf::new_error(templates::error::directory_exists);
}

const leaf::result<int> new_command::run(std::vector<std::string_view> args) {
  auto create_folder = templates::create_project_folder(std::string(args.at(0)));
  if (!create_folder) {
    return create_folder.error();
  }

  return EXIT_SUCCESS;
}

