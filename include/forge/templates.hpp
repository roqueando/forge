#pragma once
#include <boost/leaf.hpp>
#include <filesystem>
#include <unordered_map>

namespace fs = std::filesystem;
namespace leaf = boost::leaf;

namespace templates
{
  struct default_template 
  {
    std::string project_name;
    fs::path cmake_lists_path;
    fs::path readme_path;
    fs::path makefile_path;
    fs::path packages_path;
  };

  enum class error
  {
    project_name_required,
    directory_exists,
    directory_not_created,
    error_creating_root_files
  };
  const leaf::result<fs::path> create_project_folder(std::string);
  const leaf::result<int> generate_root_files(default_template);

  const std::string process_template(const std::string, const std::unordered_map<std::string, std::string>);

  const std::string readme_template = R"(
# {{PROJECT_NAME}}
> {{PROJECT_NAME}}

### updates and improvements

The project still in development and the next updates will be the following:

- [ ] put here all next updates

## 💻 pre-requisites

Before start, verify if you have the following things:
- you have installed the most recent version of [Clang](https://releases.llvm.org/download.html) or [GCC](https://gcc.gnu.org/install/download.html)
- you have any of `windows`, `macos`, `linux` operating system

## 🚀 installing {{PROJECT_NAME}}
To install `{{PROJECT_NAME}}` you need to:
- clone repository
```sh
git clone https://github.com/{{AUTHOR}}/{{PROJECT_NAME}}.git
```
- build and test
```sh
make build
```
  )";

  const std::string packages_template = R"(
include(FetchContent)

# example package to use leaf::result<T>
FetchContent_Declare(
  leaf
  GIT_REPOSITORY https://github.com/boostorg/leaf.git
  GIT_TAG boost-1.82.0
  GIT_SHALLOW ON)

# base package for google testing
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
    GIT_SHALLOW ON)
endif()

FetchContent_MakeAvailable(googletest leaf)
  )";

  const std::string makefile_template = R"(
TARGET = {{PROJECT_NAME}}
BUILDDIR = build/debug
SRCDIR = src

run: $(BUILDDIR)/Makefile
	@cd $(BUILDDIR) && ./$(TARGET)

build: $(BUILDDIR)/Makefile
	@cmake --build build/debug
	@ln -sf $(BUILDDIR)/compile_commands.json .

$(BUILDDIR)/Makefile:
	@cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=20 -B build/debug 

clean:
	@$(MAKE) -C $(BUILDDIR) clean
	@rm -rf $(BUILDDIR)

.PHONY: build clean
  )";

  const std::string cmake_lists_template = R"(
  cmake_minimum_required(VERSION 3.22)

  set({{PROJECT_SET_NAME}}_PROJECT_NAME {{project_name}})
  set({{PROJECT_SET_NAME}}_SOURCE_DIR src)
  set({{PROJECT_SET_NAME}}_SOURCE ${{{project_name}}_SOURCE_DIR}/main.cpp)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set({{PROJECT_SET_NAME}}_PROJECT_VERSION 0.1)
  set({{PROJECT_SET_NAME}}_LIBRARY_NAME {{project_name}})
  set({{PROJECT_SET_NAME}}_BINARY_NAME {{project_name}}-bin)
  SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")

  include(cmake/UniversalAppleBuild.cmake)

  project(
    ${{{PROJECT_SET_NAME}}_PROJECT_NAME}
    VERSION ${{{PROJECT_SET_NAME}}_PROJECT_VERSION}
    DESCRIPTION "{{PROJECT_SET_NAME}} project description"
    LANGUAGES CXX)

  include(cmake/StandardProjectSettings.cmake)
  include(cmake/CompilerWarnings.cmake)

  add_executable(${{{PROJECT_SET_NAME}}_BINARY_NAME} src/main.cpp)
  set_property(TARGET ${{{PROJECT_SET_NAME}}_BINARY_NAME} PROPERTY OUTPUT_NAME {{project_name}})

  target_link_libraries(${{{PROJECT_SET_NAME}}_BINARY_NAME} PUBLIC ${{{project_name}}_LIBRARY_NAME})
  target_compile_features(${{{PROJECT_SET_NAME}}_BINARY_NAME} PRIVATE cxx_std_20)

  include(packages.cmake)
  add_subdirectory(src)
  add_subdirectory(test)
  )";

};
