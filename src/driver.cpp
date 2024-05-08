#include "driver.hpp"
#include "parser.hpp"

#include "visitors/printing_visitor.hpp"

namespace nezoku {

Driver::Driver()
    : scanner(*this)
    , parser(*this, scanner) {
}

int Driver::parse(const std::string& f) {
    file = f;
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int res = parser();
    std::cout << "parser " << res << std::endl;
    scan_end();
    return res;
}

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
    
    if (!file.empty() && file != "-") {
        stream.open(file);
        std::cout << file << std::endl;
        scanner.yyrestart(&stream);
    }
}

void Driver::scan_end() {
    stream.close();
}

void Driver::print_tree(const std::string& filename) {
    auto visitor = PrintingVisitor(filename);
    visitor.visit(program);
}

}; // namespace nezoku
