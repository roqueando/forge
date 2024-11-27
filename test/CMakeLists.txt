enable_testing()
if(BUILD_TESTING AND CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_executable(forge-test cli_test.cpp template_test.cpp)
  target_link_libraries(forge-test PRIVATE GTest::gtest_main ${FORGE_LIBRARY_NAME})

  include(GoogleTest)
  gtest_discover_tests(forge-test)
  add_custom_command(
    TARGET forge-test
    POST_BUILD
    COMMAND forge-test
    COMMENT "Running unit tests after build..."
    )
endif()

