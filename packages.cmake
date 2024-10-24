include(cmake/CPM.cmake)

CPMAddPackage(
  NAME argparse
  GITHUB_REPOSITORY p-ranav/argparse
  GIT_TAG v3.1
  GIT_SHALLOW ON
  )

CPMAddPackage(
  NAME expected
  GITHUB_REPOSITORY TartanLlama/expected
  GIT_TAG v1.1.0
  GIT_SHALLOW ON)
