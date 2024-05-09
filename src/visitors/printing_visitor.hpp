#ifndef PRINTING_VISITOR_HPP
#define PRINTING_VISITOR_HPP

#include <fstream>
#include <cassert>
#include <string>

#include "visitor.hpp"

namespace nezoku {

class PrintingVisitor final: public Visitor {
public:
    PrintingVisitor(const std::string& file);
    ~PrintingVisitor() override;

    void visit(TranslationUnit* translation_unit) override;
    void visit(FunctionDefinition* function_definition) override;
    void visit(Declaration* declaration) override;

    void visit(CompoundStatement* compound_statement) override;
    void visit(ExpressionStatement* expression_statement) override;
    void visit(ReturnStatement* return_statement) override;
    void visit(ContinueStatement* continue_statement) override;
    void visit(BreakStatement* break_statement) override;
    void visit(SelectionStatement* selection_statement) override;
    void visit(IterationStatement* iteration_statement) override;

    void visit(AssignmentExpression* assignment_expression) override;
    void visit(LorExpression* logical_or_expression) override;
    void visit(LandExpression* logical_and_expression) override;
    void visit(OrExpression* inclusive_or_expression) override;
    void visit(XorExpression* exclusive_or_expression) override;
    void visit(AndExpression* and_expression) override;
    void visit(EqExpression* eq_expression) override;
    void visit(NeqExpression* neq_expression) override;
    void visit(LessExpression* less_expression) override;
    void visit(GreaterExpression* greater_expression) override;
    void visit(LeqExpression* leq_expression) override;
    void visit(GeqExpression* geq_expression) override;
    void visit(ShlExpression* shl_expression) override;
    void visit(ShrExpression* shr_expression) override;
    void visit(AddExpression* add_expression) override;
    void visit(SubExpression* sub_expression) override;
    void visit(MulExpression* mul_expression) override;
    void visit(DivExpression* div_expression) override;
    void visit(ModExpression* mod_expression) override;
    void visit(IdentifierExpression* identifier_expression) override;
    void visit(ConstantExpression* constant_expression) override;
    void visit(StringExpression* string_expression) override;

private:
    void print_tabs();

    template<class T>
    void visit_binary_op(T* op_expression, const std::string& op_string);

private:
    size_t tabs_{0};
    std::ofstream stream_;
};

}; // namespace nezoku

#endif // PRINTING_VISITOR_HPP
