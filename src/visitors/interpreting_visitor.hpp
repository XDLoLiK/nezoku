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
    ~InterpretingVisitor();

    void visit(TranslationUnit* translation_unit);
    void visit(Statement* statement);
    void visit(Expression* expression);
    void visit(Declaration* declaration);
    void visit(FunctionDefinition* function_definition);
    void visit(CompoundStatement* compound_statement);
    void visit(ExpressionStatement* expression_statement);
    void visit(ReturnStatement* return_statement);
    void visit(ContinueStatement* continue_statement);
    void visit(SelectionStatement* selection_statement);
    void visit(BreakStatement* break_statement);
    void visit(AssignmentExpression* assignment_expression);
    void visit(LorExpression* logical_or_expression);
    void visit(LandExpression* logical_and_expression);
    void visit(OrExpression* inclusive_or_expression);
    void visit(XorExpression* exclusive_or_expression);
    void visit(AndExpression* and_expression);
    void visit(EqExpression* eq_expression);
    void visit(NeqExpression* neq_expression);
    void visit(LessExpression* less_expression);
    void visit(GreaterExpression* greater_expression);
    void visit(LeqExpression* leq_expression);
    void visit(GeqExpression* geq_expression);
    void visit(ShlExpression* shl_expression);
    void visit(ShrExpression* shr_expression);
    void visit(AddExpression* add_expression);
    void visit(SubExpression* sub_expression);
    void visit(MulExpression* mul_expression);
    void visit(DivExpression* div_expression);
    void visit(ModExpression* mod_expression);

private:
    std::ostream& stream_;
};

}; // namespace nezoku

#endif // INTERPRETING_VISITOR_HPP
