#include "compound_statement.hpp"
#include "declaration.hpp"
#include "statement.hpp"
#include "visitors/visitor.hpp"

namespace nezoku {

template<class... Ts> struct DeletingVisitor: Ts... { using Ts::operator()...; };
template<class... Ts> DeletingVisitor(Ts...) -> DeletingVisitor<Ts...>;

CompoundStatement::CompoundStatement() {}

CompoundStatement::CompoundStatement(std::vector<BlockItem> block_item_list)
    : block_item_list_(std::move(block_item_list)) {}

CompoundStatement::~CompoundStatement() {
    for (const auto& block_item: block_item_list_) {
        std::visit(
            DeletingVisitor{
                [](Declaration* declaration) { delete declaration; },
                [](Statement* statement) { delete statement; }
            },
            block_item
        );
    }
}

void CompoundStatement::accept_visitor(Visitor* visitor) {
    visitor->visit(this);   
}

[[nodiscard]]
auto CompoundStatement::block_item_list() const noexcept -> const std::vector<BlockItem>& {
    return block_item_list_;
}

}; // namespace nezoku
