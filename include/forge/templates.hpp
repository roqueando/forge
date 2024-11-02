#pragma once
#include <boost/leaf.hpp>
#include <filesystem>

namespace fs = std::filesystem;
namespace leaf = boost::leaf;

namespace templates
{

  enum class error
  {
    project_name_required,
    directory_exists
  };
  const leaf::result<fs::path> create_project_folder(std::string);
  //const leaf::result<int> generate_root_files();
};
