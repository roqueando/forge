#include <boost/leaf/error.hpp>
#include <cstdlib>
#include <iostream>
#include <forge/new_command.hpp>
#include <forge/cli.hpp>
#include <filesystem>

namespace fs = std::filesystem;

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
  std::cout << destination << std::endl;
  if (!fs::exists(destination)) {
    fs::create_directory(destination);
    return EXIT_SUCCESS;
  }

  return leaf::new_error(new_command::error::directory_exists);
}

const leaf::result<int> new_command::run(std::vector<std::string_view> args) {
  auto result = leaf::try_handle_some(
    [&]() -> leaf::result<int> {
      return ::create_project_folder(std::string(args.at(0)));
    },

    [](leaf::match<new_command::error, new_command::error::directory_exists>) -> leaf::result<int> {
      return EXIT_FAILURE;
    }
  );

  if (result.has_error()) {
    return result.error();
  }

  return result;
}

