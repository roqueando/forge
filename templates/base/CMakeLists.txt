cmake_minimum_required(VERSION 3.22)

set(<PROJECT_NAME>_PROJECT_NAME <project_name>)
set(<PROJECT_NAME>_SOURCE_DIR src)
set(<PROJECT_NAME>_SOURCE ${<PROJECT_NAME>_SOURCE_DIR}/main.cpp)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(<PROJECT_NAME>_PROJECT_VERSION 0.1)
set(<PROJECT_NAME>_LIBRARY_NAME <project_name>)
set(<PROJECT_NAME>_BINARY_NAME <project_name>-bin)
SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")

include(cmake/UniversalAppleBuild.cmake)

project(
  ${<PROJECT_NAME>_PROJECT_NAME}
  VERSION ${<PROJECT_NAME>_PROJECT_VERSION}
  DESCRIPTION "<project_name> description"
  LANGUAGES CXX)

include(cmake/StandardProjectSettings.cmake)
include(cmake/CompilerWarnings.cmake)

add_executable(${<PROJECT_NAME>_BINARY_NAME} src/main.cpp)
set_property(TARGET ${<PROJECT_NAME>_BINARY_NAME} PROPERTY OUTPUT_NAME <project_name>)

target_link_libraries(${<PROJECT_NAME>_BINARY_NAME} PUBLIC ${<PROJECT_NAME>_LIBRARY_NAME})
target_compile_features(${<PROJECT_NAME>_BINARY_NAME} PRIVATE cxx_std_20)

include(packages.cmake)
add_subdirectory(src)
add_subdirectory(test)
