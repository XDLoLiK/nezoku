#include "translation_unit.hpp"
#include "declaration.hpp"
#include "function_definition.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

template<class... Ts> struct DeletingVisitor: Ts... { using Ts::operator()...; };
template<class... Ts> DeletingVisitor(Ts...) -> DeletingVisitor<Ts...>;

void TranslationUnit::accept_visitor(Visitor* visitor) {
    visitor->visit(this);
}

TranslationUnit::~TranslationUnit() {
    for (const auto& external_declaration: external_declarations_) {
        std::visit(
            DeletingVisitor{
                [](Declaration* declaration) { delete declaration; },
                [](FunctionDefinition* function_definition) { delete function_definition; }
            },
            external_declaration
        );
    }
}

void TranslationUnit::add_external_declaration(ExternalDeclaration ext_decl) {
    external_declarations_.push_back(std::move(ext_decl));
}

[[nodiscard]]
auto TranslationUnit::external_declarations() const noexcept -> const std::vector<ExternalDeclaration>& {
    return external_declarations_;
}

}; // namespace nezoku
