#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <fstream>
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
    
    int parse(const std::string& file_name);
    
    void trace_scanning(bool flag);
    void trace_parsing(bool flag);
    void translation_unit(TranslationUnit* translation_unit);
    [[nodiscard]]
    auto location() noexcept -> yy::location&;

    void scan_begin();
    void scan_end();

    void print_tree(const std::string& filename);
    void compile(const std::string& filename);
    void interpret(const std::string& filename);

private:
    bool trace_scanning_{false};
    bool trace_parsing_{false};
    std::string file_{};
    std::ifstream stream_{};
    Scanner scanner_;
    yy::parser parser_;
    yy::location location_{};
    TranslationUnit* translation_unit_{nullptr};
};

} // namespace nezoku

#endif // DRIVER_HPP
