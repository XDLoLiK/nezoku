#include <iostream>

#include "driver.hpp"
#include "cmdline.hpp"

int main(int argc, char** argv) {
    nezoku::Driver driver;
    nezoku::CmdLineParser parser;
    std::vector<std::string> sources;
    std::string output = "a.ll";
    bool next_output = false;

    parser.add_default([&](const std::string& file_name) -> bool {
        if (next_output) {
            next_output = false;
            output = file_name;
        } else {
            sources.push_back(file_name);
        }

        if (file_name.starts_with("-")) {
            return false;
        } else {
            return true;
        }
    });

    parser.add_callback("--trace-parsing", [&](const std::string&) { driver.trace_parsing(true); });
    parser.add_callback("--trace-scanning", [&](const std::string&) { driver.trace_scanning(true); });
    parser.add_callback("--emit-llvm", [&](const std::string&) { driver.emit_llvm(true); });
    parser.add_callback("--ast-dump", [&](const std::string&) { driver.ast_dump(true); });
    parser.add_callback("-o", [&](const std::string&) { next_output = true; });

    std::vector<std::string> args;

    for (int i = 1; i < argc; i++) {
        auto arg = argv[i];
        args.push_back(std::string(arg));
    }

    parser.parse_args(args);
    driver.compile(sources, output);
    return 0;
}
