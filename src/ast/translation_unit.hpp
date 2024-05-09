#ifndef TRANSLATION_UNIT_HPP
#define TRANSLATION_UNIT_HPP

#include <variant>
#include <vector>

#include "common.hpp"
#include "accepter.hpp"

namespace nezoku {

class TranslationUnit: public Accepter {
    using ExternalDeclaration = std::variant<Declaration*, FunctionDefinition*>;

public:
    ~TranslationUnit() override;

    void accept_visitor(Visitor* visitor) override;

    void add_external_declaration(ExternalDeclaration ext_decl);

    [[nodiscard]]
    auto external_declarations() const noexcept -> const std::vector<ExternalDeclaration>&;

private:
    std::vector<ExternalDeclaration> external_declarations_;
};

}; // namespace nezoku

#endif // TRANSLATION_UNIT_HPP
