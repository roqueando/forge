#include <iostream>
#include <forge/cli.hpp>
#include <argparse/argparse.hpp>
#include <tl/expected.hpp>
#include <memory>

using namespace argparse;

const void cli::version()
{
  std::cout << cli::VERSION << "\n";
}

const tl::expected<std::shared_ptr<ArgumentParser>, cli::error> cli::setup(const std::string program_name, int argc, char *argv[])
{
  std::shared_ptr<ArgumentParser> program = std::make_shared<ArgumentParser>(program_name);

  ArgumentParser init_command("init");
  init_command.add_description("initialize a project by given name");
  init_command.add_argument("project_name")
    .required()
    .help("project name to initialize");

  //init_command.add_argument("-t", "--template")
  //  .default_value("base")
  //  .help("template to be created [base | modular(soon)]");

  init_command.parse_args(argc, argv);
  program->add_subparser(init_command);

  try
  {
    program->parse_args(argc, argv);
    //init_command.parse_args(argc, argv);
    return program;
  }
  catch (std::exception &err)
  {
    std::cerr << err.what() << std::endl;
    std::cerr << *program;
    return tl::unexpected(cli::error::parse_error);
  }
}

const tl::expected<cli::response, cli::error> cli::run(std::shared_ptr<ArgumentParser> program)
{
  const auto p = program.get();

  if (p->get<bool>("--version") == true || p->get<bool>("-v") == true) {
    cli::version();
    return cli::response::ok;
  }

  if (p->is_subcommand_used("init")) {
    const auto project_name = p->at<ArgumentParser>("init")
      .get<std::string>("project_name");

    std::cout << "initializing [" << project_name << "]..." << "\n";
    return cli::response::ok;
  }

  return tl::unexpected(cli::error::command_error);
}

const cli::command cli::parse(int argc, char *argv[])
{
  // TODO do something
}

