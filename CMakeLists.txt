cmake_minimum_required(VERSION 3.22)

set(RAWR_PROJECT_NAME rawr)
set(RAWR_SOURCE_DIR src)
set(RAWR_SOURCE ${RAWR_SOURCE_DIR}/main.cpp)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(RAWR_PROJECT_VERSION 0.1)
set(RAWR_LIBRARY_NAME rawr)
set(RAWR_BINARY_NAME rawr-bin)
#set(CMAKE_C_COMPILER "/usr/bin/clang")
#set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

include(cmake/UniversalAppleBuild.cmake)

project(
  ${RAWR_PROJECT_NAME}
  VERSION ${RAWR_PROJECT_VERSION}
  DESCRIPTION "A CLI Project for generate rawr projects"
  LANGUAGES CXX)

include(cmake/StandardProjectSettings.cmake)
#add_library(project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
#set_project_warnings(project_warnings)


add_executable(${RAWR_BINARY_NAME} src/main.cpp)
set_property(TARGET ${RAWR_BINARY_NAME} PROPERTY OUTPUT_NAME rawr)

target_link_libraries(${RAWR_BINARY_NAME} PUBLIC ${RAWR_LIBRARY_NAME})
target_compile_features(${RAWR_BINARY_NAME} PRIVATE cxx_std_23)

include(packages.cmake)
add_subdirectory(src)

