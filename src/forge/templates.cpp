#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <forge/templates.hpp>
#include <fstream>
#include <unordered_map>

namespace fs = std::filesystem;

const leaf::result<fs::path>
templates::create_project_folder(std::string project_name) {
  const fs::path destination = fs::current_path().concat("/").concat(
      project_name.begin(), project_name.end());

  if (!fs::exists(destination)) {
    fs::create_directory(destination);

    return destination;
  }

  return leaf::new_error(templates::error::directory_exists);
}

const leaf::result<int>
templates::generate_root_files(templates::default_template p) {
  const fs::path destination = fs::current_path().concat("/").concat(
      p.project_name.begin(), p.project_name.end());

  if (!fs::exists(destination)) {
    return leaf::new_error(templates::error::directory_not_created);
  }

  std::string project_upper;

  std::transform(p.project_name.begin(), p.project_name.end(),
                 p.project_name.begin(),
                 [](auto x) { return std::toupper(x); });

  std::unordered_map<std::string, std::string> values = {
      {"project_name", p.project_name}, {"PROJECT_SET_NAME", project_upper}};

  // TODO: create root files

  std::ofstream cmake_lists_path(p.cmake_lists_path);
  std::ofstream readme_path(p.readme_path);
  std::ofstream makefile_path(p.makefile_path);
  std::ofstream packages_path(p.packages_path);

  if (cmake_lists_path) {
    cmake_lists_path << templates::process_template(
        templates::cmake_lists_template, values);
  }
    
  if (readme_path)
    readme_path << templates::process_template(templates::readme_template,
                                               values);

  if (makefile_path)
    makefile_path << templates::process_template(templates::makefile_template,
                                                 values);

  if (packages_path)
    packages_path << templates::process_template(templates::packages_template,
                                                 values);
  if (cmake_lists_path.good() && readme_path.good() && makefile_path.good() packages_path.good()) {
    cmake_lists_path.close();
    readme_path.close();
    makefile_path.close();
    packages_path.close();
    return EXIT_SUCCESS;
  }

  return leaf::new_error(templates::error::error_creating_root_files);
}

const std::string templates::process_template(
    const std::string template_text,
    const std::unordered_map<std::string, std::string> values) {
  std::string processed_text = template_text;

  for (const auto &[key, value] : values) {
    std::string placeholder = "{{" + key + "}}";
    size_t pos = processed_text.find(placeholder);
    while (pos != std::string::npos) {
      processed_text.replace(pos, placeholder.length(), value);
      pos = processed_text.find(placeholder, pos + value.length());
    }
  }
  return processed_text;
}
