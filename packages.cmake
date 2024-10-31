include(cmake/CPM.cmake)

# example package to use std::expected in C++ 17/20
CPMAddPackage(
  NAME expected
  GITHUB_REPOSITORY TartanLlama/expected
  GIT_TAG v1.1.0
  GIT_SHALLOW ON)

CPMAddPackage(
  NAME leaf
  GITHUB_REPOSITORY boostorg/leaf
  GIT_TAG boost-1.82.0
  GIT_SHALLOW ON)

# base package for google testing
CPMAddPackage(
  NAME googletest
  GITHUB_REPOSITORY google/googletest
  GIT_TAG v1.15.2
  GIT_SHALLOW ON)

if (leaf_ADDED)
  add_library(leaf INTERFACE IMPORTED)
  target_include_directories(leaf INTERFACE "${leaf_SOURCE_DIR}/include")
endif()
