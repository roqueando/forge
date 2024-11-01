include(cmake/CPM.cmake)

# NOTE: you can edit this as you want,
# I'll leave here two packages that I used in forge
# The usage for CPM is simple
#
#CPMAddPackage(
#  NAME <name to be available to link>
#  GITHUB_REPOSITORY <only author/repo>
#  GIT_TAG <the latest git tag or you can use GIT_VERSION x.x.x without the complete tag name>
#  GIT_SHALLOW ON <avoids deep clone of the git project>
# )

# example package to use leaf::result<T>
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

# here is for header only projects that you need to access
# always will be the name available like leaf
# and the _ADDED suffix to check if the dependency was added
if (leaf_ADDED)
  add_library(leaf INTERFACE IMPORTED)
  target_include_directories(leaf INTERFACE "${leaf_SOURCE_DIR}/include")
endif()
