#include <gtest/gtest.h>
#include <forge/templates.hpp>
#include <unordered_map>


TEST(TemplatesTest, PlaceholderTest)
{
  std::unordered_map<std::string, std::string> values = {
    {"project_name", "placeholder"},
    {"PROJECT_SET_NAME", "PLACEHOLDER"}
  };

  std::string result = templates::process_template(templates::cmake_lists_template, values);

  size_t found = result.find("PLACEHOLDER");

  EXPECT_NE(found, std::string::npos);
}
