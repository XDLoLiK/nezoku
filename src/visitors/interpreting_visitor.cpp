#include "interpreting_visitor.hpp"

#include "ast/translation_unit.hpp"
#include "ast/statement.hpp"
#include "ast/expression.hpp"
#include "ast/function_definition.hpp"
#include "ast/declaration.hpp"
#include "ast/compound_statement.hpp"
#include "ast/return_statement.hpp"
#include "ast/expression_statement.hpp"
#include "ast/break_statement.hpp"
#include "ast/continue_statement.hpp"
#include "ast/selection_statement.hpp"
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
#include "ast/type_specifier.hpp"

namespace nezoku {

InterpretingVisitor::InterpretingVisitor(std::ostream& stream)
    : stream_(stream) {}

InterpretingVisitor::~InterpretingVisitor() {}

void InterpretingVisitor::visit(TranslationUnit* translation_unit) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(Statement* statement) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(Expression* expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(Declaration* declaration) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(FunctionDefinition* function_definition) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(CompoundStatement* compound_statement) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(ExpressionStatement* expression_statement) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(ReturnStatement* return_statement) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(ContinueStatement* continue_statement) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(BreakStatement* break_statement) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(SelectionStatement* selection_statement) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(AssignmentExpression* assignment_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(LorExpression* logical_or_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(LandExpression* logical_and_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(OrExpression* inclusive_or_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(XorExpression* exclusive_or_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(AndExpression* and_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(EqExpression* eq_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(NeqExpression* neq_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(LessExpression* less_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(GreaterExpression* greater_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(LeqExpression* leq_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(GeqExpression* geq_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(ShlExpression* shl_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(ShrExpression* shr_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(AddExpression* add_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(SubExpression* sub_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(MulExpression* mul_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(DivExpression* div_expression) {
    // TODO: Unimplemented.
}

void InterpretingVisitor::visit(ModExpression* mod_expression) {
    // TODO: Unimplemented.
}

}; // namespace nezoku
