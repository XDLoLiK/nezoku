#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "ast/common.hpp"

namespace nezoku {

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(TranslationUnit* translation_unit) = 0;
    virtual void visit(FunctionDefinition* function_definition) = 0;
    virtual void visit(Declaration* declaration) = 0;

    virtual void visit(CompoundStatement* compound_statement) = 0;
    virtual void visit(ExpressionStatement* expression_statement) = 0;
    virtual void visit(ReturnStatement* return_statement) = 0;
    virtual void visit(ContinueStatement* continue_statement) = 0;
    virtual void visit(BreakStatement* break_statement) = 0;
    virtual void visit(SelectionStatement* selection_statement) = 0;
    virtual void visit(IterationStatement* iteration_statement) = 0;

    virtual void visit(AssignmentExpression* assignment_expressoin) = 0;
    virtual void visit(LorExpression* logical_or_expressoin) = 0;
    virtual void visit(LandExpression* logical_and_expressoin) = 0;
    virtual void visit(OrExpression* inclusive_or_expressoin) = 0;
    virtual void visit(XorExpression* exclusive_or_expressoin) = 0;
    virtual void visit(AndExpression* and_expressoin) = 0;
    virtual void visit(EqExpression* eq_expression) = 0;
    virtual void visit(NeqExpression* neq_expression) = 0;
    virtual void visit(LessExpression* less_expression) = 0;
    virtual void visit(GreaterExpression* greater_expression) = 0;
    virtual void visit(LeqExpression* leq_expression) = 0;
    virtual void visit(GeqExpression* geq_expression) = 0;
    virtual void visit(ShlExpression* shl_expression) = 0;
    virtual void visit(ShrExpression* shr_expression) = 0;
    virtual void visit(AddExpression* add_expression) = 0;
    virtual void visit(SubExpression* sub_expression) = 0;
    virtual void visit(MulExpression* mul_expression) = 0;
    virtual void visit(DivExpression* div_expression) = 0;
    virtual void visit(ModExpression* mod_expression) = 0;
    virtual void visit(FunctionCallExpression* function_call_expression) = 0;
    virtual void visit(IdentifierExpression* identifier_expression) = 0;
    virtual void visit(ConstantExpression* constant_expression) = 0;
    virtual void visit(StringExpression* string_expression) = 0;
};

}; // namespace nezoku

#endif // VISITOR_HPP
