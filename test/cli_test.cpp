#include <gtest/gtest.h>
#include <forge/cli.hpp>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;

auto generate_parsed_new_command()
{
  const int argc = 3;
  const char *args[] = {"forge", "new", "project_name"};
  char **argv = new char *[argc + 1];
  for (int i = 0; i < argc; ++i)
  {
    argv[i] = new char[strlen(args[i]) + 1];
    std::strcpy(argv[i], args[i]);
  }

  return cli::parse(argc, argv);
}

void tear_down(std::string project_name)
{
  const fs::path destination = fs::current_path()
    .concat("/")
    .concat(project_name.begin(), project_name.end());
  fs::remove_all(destination);
}

TEST(CliTest, ParsingTest)
{
  const auto fn = [](std::vector<std::string_view>)
  {
    return 0;
  };
  const cli::command result{"new", {"new", "project_name"}, fn};

  const auto parse_expected = generate_parsed_new_command();
  const auto cmd = parse_expected.value();

  EXPECT_EQ(parse_expected.has_error(), false);
  EXPECT_EQ(cmd.name, result.name);
}

TEST(CliTest, CreateProject)
{
  const auto cmd = generate_parsed_new_command().value();
  const auto result = cmd.action(cmd.args);

  std::cout << result.has_error() << std::endl;
  
  EXPECT_EQ(result, EXIT_SUCCESS);

  tear_down(std::string(cmd.args.at(0)));
}
