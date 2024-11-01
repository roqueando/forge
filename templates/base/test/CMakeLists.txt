enable_testing()
if(BUILD_TESTING)
  add_executable(<project_name>-test cli_test.cpp)
  target_link_libraries(<project_name>-test PRIVATE GTest::gtest_main ${<project_name>_LIBRARY_NAME})

  include(GoogleTest)
  gtest_discover_tests(<project_name>-test)
  add_custom_command(
    TARGET <project_name>-test
    POST_BUILD
    COMMAND <project_name>-test
    COMMENT "Running unit tests after build..."
    )
endif()

