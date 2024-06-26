#ifndef CODEGEN_VISITOR_HPP
#define CODEGEN_VISITOR_HPP

#include <iostream>
#include <memory>
#include <fstream>
#include <functional>
#include <cassert>
#include <string>
#include <stack>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

#include "visitor.hpp"
#include "scope.hpp"
#include "ast/type_specifier.hpp"
#include "ast/assignment_operator.hpp"

namespace nezoku {

class CodegenVisitor final: public Visitor {
    using BinaryOp = std::function<llvm::Value* (llvm::Value*, llvm::Value*)>;

    struct Value {
        llvm::Type* type;
        llvm::Value* value;
        bool is_signed;

        Value(llvm::Type* type, llvm::Value* value, bool is_signed = true)
            : type(type)
            , value(value)
            , is_signed(is_signed) {}
    };

public:
    CodegenVisitor(const std::string& file_name);
    virtual ~CodegenVisitor() = default;

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
    void visit(FunctionCallExpression* function_call_expression) override;
    void visit(IdentifierExpression* identifier_expression) override;
    void visit(ConstantExpression* constant_expression) override;
    void visit(StringExpression* string_expression) override;

private:
    llvm::FunctionType* printf_type();
    llvm::FunctionType* scanf_type();

    template<class T>
    void visit_binary_op(T* binary_op, BinaryOp op_func);

    llvm::BasicBlock* generate_block(const std::string& block_name);

    llvm::Type* type_to_llvm_type(TypeSpecifier type);
    bool type_is_signed(TypeSpecifier type);

private:
    std::string file_;
    llvm::LLVMContext context_{};
    llvm::IRBuilder<> builder_;
    std::unique_ptr<llvm::Module> module_;
    llvm::Function* current_function_{nullptr};
    llvm::BasicBlock* cond_block_{nullptr};
    llvm::BasicBlock* out_block_{nullptr};
    std::stack<llvm::Value*> latest_values_;
    std::shared_ptr<Scope<Value>> current_scope_;
    std::unordered_map<std::string, llvm::FunctionType*> functions_{};
    std::vector<llvm::BasicBlock*> blocks_{};
};

}; // namespace nezoku

#endif // CODEGEN_VISITOR_HPP
