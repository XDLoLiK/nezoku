#include <iostream>
#include <filesystem>

#include "driver.hpp"
#include "cmdline.hpp"

int main(int argc, const char** argv) {
    nezoku::Driver driver;
    nezoku::CmdLineParser parser;
    std::vector<std::string> sources;
    std::string output = "a.ll";
    bool next_output = false;

    parser.add_default([&](const std::string& file_name) -> bool {
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

    parser.add_callback("--trace-parsing", [&]() { driver.trace_parsing(true); });
    parser.add_callback("--trace-scanning", [&]() { driver.trace_scanning(true); });
    parser.add_callback("--emit-llvm", [&]() { driver.emit_llvm(true); });
    parser.add_callback("--ast-dump", [&]() { driver.ast_dump(true); });
    parser.add_callback("-o", [&]() { next_output = true; });

    std::vector<std::string> args;

    for (int i = 1; i < argc; i++) {
        auto arg = std::string(argv[i]);
        args.push_back(arg);
    }

    parser.parse_args(args);
    driver.compile(sources, output);
    return 0;
}
