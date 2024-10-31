#include <gtest/gtest.h>
#include <rawr/cli.hpp>

TEST(CliTest, ParsingTest) {
  const auto fn = [](std::vector<std::string_view>) {
    return cli::response::ok;
  };
  const cli::command result{"init", {"init", "project_name"}, fn};
  std::cout << result.name << "\n";
  EXPECT_EQ("hello", "hello");
}
