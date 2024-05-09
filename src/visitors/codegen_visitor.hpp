#ifndef CODEGEN_VISITOR_HPP
#define CODEGEN_VISITOR_HPP

#include <memory>
#include <fstream>
#include <cassert>
#include <string>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

#include "visitor.hpp"

namespace nezoku {

class CodegenVisitor final: public Visitor {
public:
    CodegenVisitor(const std::string& file);
    ~CodegenVisitor() override;

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
    size_t tabs_{0};
    std::ofstream stream_;
    llvm::LLVMContext context_{};
    llvm::IRBuilder<> builder_;
    std::unique_ptr<llvm::Module> module_;
    FunctionDefinition* current_function_{nullptr};
    llvm::BasicBlock* current_block_{nullptr};
};

}; // namespace nezoku

#endif // CODEGEN_VISITOR_HPP
