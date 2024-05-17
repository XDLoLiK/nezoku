#include "driver.hpp"
#include "parser.hpp"

#include "visitors/printing_visitor.hpp"
#include "visitors/interpreting_visitor.hpp"
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

void Driver::emit_llvm(bool flag) {
    emit_llvm_ = flag;
}

void Driver::ast_dump(bool flag) {
    ast_dump_ = flag;
}

void Driver::translation_unit(TranslationUnit* translation_unit) {
    translation_unit_ = translation_unit;
}

[[nodiscard]]
auto Driver::location() noexcept -> yy::location& {
    return location_;
}

void Driver::compile(const std::vector<std::string>& sources, [[maybe_unused]] const std::string& output) {
    for (const auto& src_file: sources) {
        if (parse(src_file)) {
            std::cerr << "Error while parsing " << src_file << std::endl;
            return;
        }

        if (ast_dump_) {
            auto text_file = src_file + ".txt";
            print_tree(text_file);
        }

        auto ir_file = src_file + ".ll";
        auto visitor = CodegenVisitor(ir_file);
        visitor.visit(translation_unit_);
        visitor.write_to(ir_file);
    }
}

void Driver::print_tree(const std::string& file_name) {
    auto visitor = PrintingVisitor(file_name);
    visitor.visit(translation_unit_);
}

void Driver::interpret(const std::string& file_name) {
    auto visitor = InterpretingVisitor(file_name);
    visitor.visit(translation_unit_);
}

int Driver::parse(const std::string& file_name) {
    curr_src_file_ = file_name;
    location_.initialize(&curr_src_file_);
    scan_begin();
    parser_.set_debug_level(trace_parsing_);
    auto res = parser_();
    scan_end();
    return res;
}

void Driver::scan_begin() {
    if (curr_src_file_.empty()) {
        return;
    }

    scanner_.set_debug(trace_scanning_);
    stream_.open(curr_src_file_);
    std::cout << curr_src_file_ << std::endl;
    scanner_.yyrestart(&stream_);
}

void Driver::scan_end() {
    stream_.close();
}

}; // namespace nezoku
