#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <fstream>
#include <filesystem>
#include <map>
#include <string>

#include "scanner.hpp"
#include "parser.hpp"

#include "ast/translation_unit.hpp"

namespace nezoku {

class Driver {
public:
    Driver();
    ~Driver();
    
    void trace_scanning(bool flag);
    void trace_parsing(bool flag);
    void emit_llvm(bool flag);
    void ast_dump(bool flag);
    void translation_unit(TranslationUnit* translation_unit);

    [[nodiscard]]
    auto location() noexcept -> yy::location&;

    void compile(const std::vector<std::string>& sources, const std::string& output = "a.ll");

private:
    void print_tree(const std::string& file_name);
    void interpret(const std::string& file_name);

    int parse(const std::string& file_name);
    void scan_begin();
    void scan_end();

private:
    Scanner scanner_;
    yy::parser parser_;
    bool trace_scanning_{false};
    bool trace_parsing_{false};
    bool emit_llvm_{false};
    bool ast_dump_{false};
    std::string curr_file_{};
    std::ifstream stream_{};
    yy::location location_{};
    TranslationUnit* translation_unit_{nullptr};
};

} // namespace nezoku

#endif // DRIVER_HPP
