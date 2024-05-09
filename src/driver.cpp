#include "driver.hpp"
#include "parser.hpp"

#include "visitors/printing_visitor.hpp"
#include "visitors/codegen_visitor.hpp"

namespace nezoku {

Driver::Driver()
    : scanner_(*this)
    , parser_(*this, scanner_) {
}

Driver::~Driver() {
    delete translation_unit_;
}

void Driver::trace_scanning(bool flag) {
    trace_scanning_ = flag;
}

void Driver::trace_parsing(bool flag) {
    trace_parsing_ = flag;
}

void Driver::translation_unit(TranslationUnit* translation_unit) {
    translation_unit_ = translation_unit;
}

[[nodiscard]]
auto Driver::location() noexcept -> yy::location& {
    return location_;
}

int Driver::parse(const std::string& file_name) {
    file_ = file_name;
    location_.initialize(&file_);
    scan_begin();
    parser_.set_debug_level(trace_parsing_);
    auto res = parser_();
    scan_end();
    return res;
}

void Driver::scan_begin() {
    if (file_.empty()) {
        return;
    }

    scanner_.set_debug(trace_scanning_);
    stream_.open(file_);
    std::cout << file_ << std::endl;
    scanner_.yyrestart(&stream_);
}

void Driver::scan_end() {
    stream_.close();
}

void Driver::print_tree(const std::string& file_name) {
    auto visitor = PrintingVisitor(file_name);
    visitor.visit(translation_unit_);
}

void Driver::compile(const std::string& file_name) {
    auto visitor = CodegenVisitor(file_name);
    visitor.visit(translation_unit_);
}

}; // namespace nezoku
