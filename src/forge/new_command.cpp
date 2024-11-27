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
  std::cout << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "forge [" << cli::VERSION
            << "] #new" << std::endl;
  std::cout << "-----------------------USAGE----------------------"
            << std::endl;

  std::cout
      << "#> <project_name> [required] - generate a new project in the current folder"
      << std::endl;
}

const leaf::result<int> new_command::run(std::vector<std::string_view> args)
{
  if (args.empty())
  {
    return leaf::new_error(templates::error::project_name_required);
  }

  std::string project_name = std::string(args.at(0));

  auto create_folder = templates::create_project_folder(project_name);
  if (!create_folder.has_value())
  {
    return create_folder.error();
  }

  const fs::path cmake_lists_path = fs::current_path()
                                        .concat("/")
                                        .concat(project_name.begin(), project_name.end())
                                        .concat("/CMakeLists.txt");

  templates::default_template p{
      project_name,
      new_command::generate_path("CMakeLists.txt", project_name),
      generate_path("README.md", project_name),
      generate_path("Makefile", project_name),
      generate_path("packages.cmake", project_name)};

  auto create_root_files = templates::generate_root_files(p);
  if (!create_root_files.has_value())
  {
    return create_root_files.error();
  }

  return EXIT_SUCCESS;
}

const fs::path new_command::generate_path(std::string p, std::string project_name)
{

  return fs::current_path()
      .concat("/")
      .concat(project_name.begin(), project_name.end())
      .concat("/")
      .concat(p);
}
