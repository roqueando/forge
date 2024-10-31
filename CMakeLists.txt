cmake_minimum_required(VERSION 3.22)

set(FORGE_PROJECT_NAME forge)
set(FORGE_SOURCE_DIR src)
set(FORGE_SOURCE ${FORGE_SOURCE_DIR}/main.cpp)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(FORGE_PROJECT_VERSION 0.1)
set(FORGE_LIBRARY_NAME forge)
set(FORGE_BINARY_NAME forge-bin)
SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")

include(cmake/UniversalAppleBuild.cmake)

project(
  ${FORGE_PROJECT_NAME}
  VERSION ${FORGE_PROJECT_VERSION}
  DESCRIPTION "A CLI Project for generate forge projects"
  LANGUAGES CXX)

include(cmake/StandardProjectSettings.cmake)
include(cmake/CompilerWarnings.cmake)

add_executable(${FORGE_BINARY_NAME} src/main.cpp)
set_property(TARGET ${FORGE_BINARY_NAME} PROPERTY OUTPUT_NAME forge)

target_link_libraries(${FORGE_BINARY_NAME} PUBLIC ${FORGE_LIBRARY_NAME})
target_compile_features(${FORGE_BINARY_NAME} PRIVATE cxx_std_20)

include(packages.cmake)
add_subdirectory(src)
add_subdirectory(test)
