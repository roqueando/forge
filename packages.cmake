include(cmake/CPM.cmake)

# example package to use std::expected in C++ 17/20
CPMAddPackage(
  NAME expected
  GITHUB_REPOSITORY TartanLlama/expected
  GIT_TAG v1.1.0
  GIT_SHALLOW ON)


# base package for google testing
CPMAddPackage(
  NAME googletest
  GITHUB_REPOSITORY google/googletest
  GIT_TAG v1.15.2
  GIT_SHALLOW ON)
