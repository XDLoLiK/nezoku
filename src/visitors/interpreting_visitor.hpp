#ifndef INTERPRETING_VISITOR_HPP
#define INTERPRETING_VISITOR_HPP

#include <iostream>
#include <cassert>
#include <cinttypes>
#include <any>
#include <functional>
#include <stack>

#include "visitor.hpp"
#include "scope.hpp"
#include "ast/type_specifier.hpp"
#include "ast/assignment_operator.hpp"

namespace nezoku {

class InterpretingVisitor: public Visitor {
    using Value = std::pair<TypeSpecifier, std::any>;
    using BinaryOp = std::function<Value (Value, Value)>;

public:
    InterpretingVisitor(std::ostream& stream);
    virtual ~InterpretingVisitor() = default;

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
    template<class T>
    void visit_binary_op(T* binary_op, BinaryOp op_func);

private:
    std::ostream& stream_;
    std::stack<Value> latest_values_;
    std::shared_ptr<Scope<Value>> current_scope_;
    std::shared_ptr<Scope<FunctionDefinition*>> functions_;
};

}; // namespace nezoku

#endif // INTERPRETING_VISITOR_HPP
