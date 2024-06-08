#include <iostream>
#include <filesystem>

#include "driver.hpp"
#include "cmdline.hpp"

int main(int argc, const char** argv) {
    nezoku::Driver driver;
    nezoku::CmdLineParser arg_parser;
    std::vector<std::string> sources;
    std::string output = "a.ll";
    bool next_output = false;

    arg_parser.add_default([&](const std::string& file_name) -> bool {
        if (next_output) {
            next_output = false;
            output = file_name;
            return true;
        } else {
            sources.push_back(file_name);
            auto path = std::filesystem::path(file_name);
            return std::filesystem::exists(path);
        }
    });

    arg_parser.add_callback("--trace-parsing", [&]() { driver.trace_parsing(true); });
    arg_parser.add_callback("--trace-scanning", [&]() { driver.trace_scanning(true); });
    arg_parser.add_callback("--emit-llvm", [&]() { driver.emit_llvm(true); });
    arg_parser.add_callback("--ast-dump", [&]() { driver.ast_dump(true); });
    arg_parser.add_callback("-o", [&]() { next_output = true; });

    std::vector<std::string> args;

    for (int i = 1; i < argc; i++) {
        auto arg = std::string(argv[i]);
        args.push_back(arg);
    }

    arg_parser.parse_args(args);
    driver.compile(sources, output);
    return 0;
}
