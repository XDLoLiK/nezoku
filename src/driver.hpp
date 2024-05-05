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
    friend class Scanner;

public:
    Driver();
    
    int parse(const std::string& file_name);

    void scan_begin();
    void scan_end();

public:
    bool trace_scanning;
    bool trace_parsing;
    int result;

    yy::location location;
    std::string file;
    Scanner scanner;
    yy::parser parser;
    TranslationUnit* program;

private:
    std::ifstream stream;
};

} // namespace nezoku

#endif // DRIVER_HPP
