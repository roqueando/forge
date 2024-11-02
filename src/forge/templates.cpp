#include <forge/templates.hpp>
#include <filesystem>

namespace fs = std::filesystem;

const leaf::result<fs::path> templates::create_project_folder(std::string project_name)
{
  //const fs::path template_path = "templates/base";
  const fs::path destination = fs::current_path()
    .concat("/")
    .concat(project_name.begin(), project_name.end());

  if (!fs::exists(destination)) {
    fs::create_directory(destination);

    return destination;
  }

  return leaf::new_error(templates::error::directory_exists);
}
