#include "codegen_visitor.hpp"

#include "ast/translation_unit.hpp"
#include "ast/function_definition.hpp"
#include "ast/declaration.hpp"

#include "ast/statement.hpp"
#include "ast/compound_statement.hpp"
#include "ast/return_statement.hpp"
#include "ast/expression_statement.hpp"
#include "ast/break_statement.hpp"
#include "ast/continue_statement.hpp"
#include "ast/selection_statement.hpp"
#include "ast/iteration_statement.hpp"

#include "ast/expression.hpp"
#include "ast/comma_expression.hpp"
#include "ast/assignment_expression.hpp"
#include "ast/logical_or_expression.hpp"
#include "ast/logical_and_expression.hpp"
#include "ast/inclusive_or_expression.hpp"
#include "ast/exclusive_or_expression.hpp"
#include "ast/and_expression.hpp"
#include "ast/eq_expression.hpp"
#include "ast/neq_expression.hpp"
#include "ast/less_expression.hpp"
#include "ast/greater_expression.hpp"
#include "ast/leq_expression.hpp"
#include "ast/geq_expression.hpp"
#include "ast/shl_expression.hpp"
#include "ast/shr_expression.hpp"
#include "ast/add_expression.hpp"
#include "ast/sub_expression.hpp"
#include "ast/mul_expression.hpp"
#include "ast/div_expression.hpp"
#include "ast/mod_expression.hpp"
#include "ast/identifier_expression.hpp"
#include "ast/constant_expression.hpp"
#include "ast/string_expression.hpp"

#include "ast/type_specifier.hpp"
#include "ast/assignment_operator.hpp"

namespace nezoku {

template<class... Ts> struct VariantVisitor: Ts... { using Ts::operator()...; };
template<class... Ts> VariantVisitor(Ts...) -> VariantVisitor<Ts...>;

CodegenVisitor::CodegenVisitor(const std::string& file)
    : stream_(file)
    , builder_(context_)
    , module_(std::make_unique<llvm::Module>(file, context_)) {}

CodegenVisitor::~CodegenVisitor() {
    stream_.close();
}

void CodegenVisitor::visit(TranslationUnit* translation_unit) {
    for (const auto& external_declaration: translation_unit->external_declarations()) {
        std::visit(
            VariantVisitor{
                [this](Declaration* declaration) { declaration->accept_visitor(this); },
                [this](FunctionDefinition* function_definition) { function_definition->accept_visitor(this); }
            },
            external_declaration
        );
    }
}

void CodegenVisitor::visit(Declaration* declaration) {}

void CodegenVisitor::visit(FunctionDefinition* function_definition) {}

void CodegenVisitor::visit(CompoundStatement* compound_statement) {
    for (const auto& block_item: compound_statement->block_item_list()) {
        std::visit(
            VariantVisitor{
                [this](Declaration* declaration) { declaration->accept_visitor(this); },
                [this](Statement* statement) { statement->accept_visitor(this); }
            },
            block_item
        );
    }
}

void CodegenVisitor::visit(ExpressionStatement* expression_statement) {
    auto expression = expression_statement->expression();

    if (expression) {
        expression->accept_visitor(this);
    }
}

void CodegenVisitor::visit(ReturnStatement* return_statement) {}

void CodegenVisitor::visit([[maybe_unused]] ContinueStatement* continue_statement) {}

void CodegenVisitor::visit([[maybe_unused]] BreakStatement* break_statement) {}

void CodegenVisitor::visit(SelectionStatement* selection_statement) {}

void CodegenVisitor::visit([[maybe_unused]] IterationStatement* iteration_statement) {}

void CodegenVisitor::visit(AssignmentExpression* assignment_expression) {}

void CodegenVisitor::visit(LorExpression* logical_or_expression) {}

void CodegenVisitor::visit(LandExpression* logical_and_expression) {}

void CodegenVisitor::visit(OrExpression* inclusive_or_expression) {}

void CodegenVisitor::visit(XorExpression* exclusive_or_expression) {}

void CodegenVisitor::visit(AndExpression* and_expression) {}

void CodegenVisitor::visit(EqExpression* eq_expression) {}

void CodegenVisitor::visit(NeqExpression* neq_expression) {}

void CodegenVisitor::visit(LessExpression* less_expression) {}

void CodegenVisitor::visit(GreaterExpression* greater_expression) {}

void CodegenVisitor::visit(LeqExpression* leq_expression) {}

void CodegenVisitor::visit(GeqExpression* geq_expression) {}

void CodegenVisitor::visit(ShlExpression* shl_expression) {}

void CodegenVisitor::visit(ShrExpression* shr_expression) {}

void CodegenVisitor::visit(AddExpression* add_expression) {}

void CodegenVisitor::visit(SubExpression* sub_expression) {}

void CodegenVisitor::visit(MulExpression* mul_expression) {}

void CodegenVisitor::visit(DivExpression* div_expression) {}

void CodegenVisitor::visit(ModExpression* mod_expression) {}

void CodegenVisitor::visit(IdentifierExpression* identifier_expression) {}

void CodegenVisitor::visit(ConstantExpression* constant_expression) {}

void CodegenVisitor::visit(StringExpression* string_expression) {}

}; // namespace nezoku
