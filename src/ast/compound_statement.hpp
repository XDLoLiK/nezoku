#ifndef COMPOUND_STATEMENT_HPP
#define COMPOUND_STATEMENT_HPP

#include <variant>
#include <vector>
#include <utility>

#include "common.hpp"
#include "statement.hpp"

namespace nezoku {


class CompoundStatement: public Statement {
    using BlockItem = std::variant<Declaration*, Statement*>;

public:
    CompoundStatement(std::vector<BlockItem> block_item_list = std::vector<BlockItem>());
    ~CompoundStatement() override;

    void accept_visitor(Visitor* visitor) override;

    [[nodiscard]]
    auto block_item_list() const noexcept -> const std::vector<BlockItem>&;

private:
    std::vector<BlockItem> block_item_list_;
};

}; // namespace nezoku

#endif // COMPOUND_STATEMENT_HPP
