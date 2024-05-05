#ifndef INTERPRETING_VISITOR_HPP
#define INTERPRETING_VISITOR_HPP

#include <iostream>
#include <cassert>
#include <cinttypes>

#include "visitor.hpp"

namespace nezoku {

class InterpretingVisitor: public Visitor {
public:
    InterpretingVisitor(std::ostream& stream);
    ~InterpretingVisitor() final;

    void visit(TranslationUnit* translation_unit) final;
    void visit(Statement* statement) final;
    void visit(Expression* expression) final;
    void visit(Declaration* declaration) final;
    void visit(FunctionDefinition* function_definition) final;
    void visit(CompoundStatement* compound_statement) final;
    void visit(ExpressionStatement* expression_statement) final;
    void visit(ReturnStatement* return_statement) final;
    void visit(ContinueStatement* continue_statement) final;
    void visit(SelectionStatement* selection_statement) final;
    void visit(BreakStatement* break_statement) final;
    void visit(AssignmentExpression* assignment_expression) final;
    void visit(LorExpression* logical_or_expression) final;
    void visit(LandExpression* logical_and_expression) final;
    void visit(OrExpression* inclusive_or_expression) final;
    void visit(XorExpression* exclusive_or_expression) final;
    void visit(AndExpression* and_expression) final;
    void visit(EqExpression* eq_expression) final;
    void visit(NeqExpression* neq_expression) final;
    void visit(LessExpression* less_expression) final;
    void visit(GreaterExpression* greater_expression) final;
    void visit(LeqExpression* leq_expression) final;
    void visit(GeqExpression* geq_expression) final;
    void visit(ShlExpression* shl_expression) final;
    void visit(ShrExpression* shr_expression) final;
    void visit(AddExpression* add_expression) final;
    void visit(SubExpression* sub_expression) final;
    void visit(MulExpression* mul_expression) final;
    void visit(DivExpression* div_expression) final;
    void visit(ModExpression* mod_expression) final;

private:
    std::ostream& stream_;
};

}; // namespace nezoku

#endif // INTERPRETING_VISITOR_HPP
