#include <gtest/gtest.h>
#include <forge/cli.hpp>

TEST(CliTest, ParsingTest) {
  const auto fn = [](std::vector<std::string_view>) {
    return 0;
  };
  const cli::command result{"new", {"new", "project_name"}, fn};

  const int argc = 3;
  const char* args[] = {"forge", "new", "project_name"};
  char** argv = new char*[argc + 1];
  for (int i = 0; i < argc; ++i) {
    argv[i] = new char[strlen(args[i]) + 1];
    std::strcpy(argv[i], args[i]);
  }

  const auto parse_expected = cli::parse(argc, argv);
  const auto cmd = parse_expected.value();

  EXPECT_EQ(parse_expected.has_error(), false);
  EXPECT_EQ(cmd.name, result.name);
}
