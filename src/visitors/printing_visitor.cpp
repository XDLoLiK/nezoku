#include "printing_visitor.hpp"

#include "ast/translation_unit.hpp"
#include "ast/function_definition.hpp"
#include "ast/declaration.hpp"

#include "ast/compound_statement.hpp"
#include "ast/return_statement.hpp"
#include "ast/expression_statement.hpp"
#include "ast/break_statement.hpp"
#include "ast/continue_statement.hpp"
#include "ast/selection_statement.hpp"
#include "ast/iteration_statement.hpp"

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

static std::string type_specifier_str(const TypeSpecifier& type) {
    switch (type) {
        case TypeSpecifier::VoidType: return "void";
        case TypeSpecifier::I8Type: return "i8";
        case TypeSpecifier::I16Type: return "i16";
        case TypeSpecifier::I32Type: return "i32";
        case TypeSpecifier::I64Type: return "i64";
        case TypeSpecifier::U8Type: return "u8";
        case TypeSpecifier::U16Type: return "u16";
        case TypeSpecifier::U32Type: return "u32";
        case TypeSpecifier::U64Type: return "u64";
        case TypeSpecifier::BoolType: return "bool";
        case TypeSpecifier::CharType: return "char";
        case TypeSpecifier::F32Type: return "f32";
        case TypeSpecifier::F64Type: return "f64";
        default: return "unknown";
    }
}

static std::string assignment_operator_str(const AssignmentOperator& op) {
    switch (op) {
        case AssignmentOperator::Assign: return "=";
        case AssignmentOperator::AddAssign: return "+=";
        case AssignmentOperator::SubAssign: return "-=";
        case AssignmentOperator::MulAssign: return "*=";
        case AssignmentOperator::DivAssign: return "/=";
        case AssignmentOperator::ModAssign: return "%=";
        case AssignmentOperator::ShlAssign: return "<<=";
        case AssignmentOperator::ShrAssign: return ">>=";
        case AssignmentOperator::AndAssign: return "&=";
        case AssignmentOperator::XorAssign: return "^=";
        case AssignmentOperator::OrAssign: return "|=";
        default: return "unknown";
    }
}

PrintingVisitor::PrintingVisitor(const std::string& file)
    : stream_(file) {}

PrintingVisitor::~PrintingVisitor() {
    stream_.close();
}

void PrintingVisitor::visit(TranslationUnit* translation_unit) {
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

void PrintingVisitor::visit(Declaration* declaration) {
    auto type = declaration->variable_type();
    auto id = declaration->variable_name();
    print_tabs();
    stream_ << "[variable]:" << std::endl;
    tabs_++;

    print_tabs();
    stream_ << "[type]: " << type_specifier_str(type) << std::endl;
    
    print_tabs();
    stream_ << "[id]: " << id << std::endl;
    
    auto init_expr = declaration->initializer();
    print_tabs();
    stream_ << "[init]:" << std::endl;

    if (init_expr) {
        tabs_++;
        init_expr->accept_visitor(this);
        tabs_--;
    }
}

void PrintingVisitor::visit(FunctionDefinition* function_definition) {
    auto type = function_definition->return_type();
    auto id = function_definition->function_name();
    print_tabs();
    stream_ << "[function]: " << type_specifier_str(type) << " " << id << std::endl;;

    auto parameters = function_definition->parameter_list();
    tabs_++;
    print_tabs();
    stream_ << "[params]:" << std::endl;
    tabs_++;

    for (const auto& param: parameters) {
        print_tabs();
        stream_ << type_specifier_str(param.first) << " " << param.second << std::endl;
    }

    auto body = function_definition->function_body();
    tabs_--;
    print_tabs();
    stream_ << "[body]:" << std::endl;
    tabs_++;

    if (body) {
        body->accept_visitor(this);
    }

    tabs_ -= 2;
}

void PrintingVisitor::visit(CompoundStatement* compound_statement) {
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

void PrintingVisitor::visit(ExpressionStatement* expression_statement) {
    auto expression = expression_statement->expression();

    if (expression) {
        expression->accept_visitor(this);
    }
}

void PrintingVisitor::visit(ReturnStatement* return_statement) {
    print_tabs();
    stream_ << "[op]: return" << std::endl;
    tabs_++;
    auto expression = return_statement->expression();

    if (expression) {
        expression->accept_visitor(this);
    }

    tabs_--;
}

void PrintingVisitor::visit([[maybe_unused]] ContinueStatement* continue_statement) {
    print_tabs();
    stream_ << "[op]: continue" << std::endl;
}

void PrintingVisitor::visit([[maybe_unused]] BreakStatement* break_statement) {
    print_tabs();
    stream_ << "[op]: break" << std::endl;
}

void PrintingVisitor::visit(SelectionStatement* selection_statement) {
    print_tabs();
    stream_ << "[branch]:" << std::endl;
    tabs_++;

    print_tabs();
    stream_ << "[if]:" << std::endl;
    tabs_++;
    auto if_cond = selection_statement->if_expression();
    if_cond->accept_visitor(this);
    tabs_--;
    
    print_tabs();
    stream_ << "[then]:" << std::endl;
    tabs_++;
    auto if_body = selection_statement->then_statement();
    if_body->accept_visitor(this);
    tabs_--;

    print_tabs();
    stream_ << "[else]:" << std::endl;
    tabs_++;
    auto else_body = selection_statement->else_statement();

    if (else_body) {
        else_body->accept_visitor(this);
    }

    tabs_ -= 2;
}

void PrintingVisitor::visit(IterationStatement* iteration_statement) {
    print_tabs();
    stream_ << "[loop]:" << std::endl;
    tabs_++;

    print_tabs();
    stream_ << "[cond]:" << std::endl;
    tabs_++;
    auto cond = iteration_statement->condition();
    cond->accept_visitor(this);
    tabs_--;

    print_tabs();
    stream_ << "[body]:" << std::endl;
    tabs_++;
    auto body = iteration_statement->body();
    body->accept_visitor(this);
    tabs_ -= 2;
}

void PrintingVisitor::visit(AssignmentExpression* assignment_expression) {
    auto op = assignment_expression->op();
    print_tabs();
    stream_ << "[op]:" << assignment_operator_str(op) << std::endl;
    tabs_++;
    auto left_expr = assignment_expression->left_expression();
    auto right_expr = assignment_expression->right_expression();
    left_expr->accept_visitor(this);
    right_expr->accept_visitor(this);
    tabs_--;
}

void PrintingVisitor::visit(LorExpression* logical_or_expression) {
    visit_binary_op(logical_or_expression, "||");
}

void PrintingVisitor::visit(LandExpression* logical_and_expression) {
    visit_binary_op(logical_and_expression, "&&");
}

void PrintingVisitor::visit(OrExpression* inclusive_or_expression) {
    visit_binary_op(inclusive_or_expression, "|");
}

void PrintingVisitor::visit(XorExpression* exclusive_or_expression) {
    visit_binary_op(exclusive_or_expression, "^");
}

void PrintingVisitor::visit(AndExpression* and_expression) {
    visit_binary_op(and_expression, "&");
}

void PrintingVisitor::visit(EqExpression* eq_expression) {
    visit_binary_op(eq_expression, "==");
}

void PrintingVisitor::visit(NeqExpression* neq_expression) {
    visit_binary_op(neq_expression, "!=");
}

void PrintingVisitor::visit(LessExpression* less_expression) {
    visit_binary_op(less_expression, "<");
}

void PrintingVisitor::visit(GreaterExpression* greater_expression) {
    visit_binary_op(greater_expression, "<");
}

void PrintingVisitor::visit(LeqExpression* leq_expression) {
    visit_binary_op(leq_expression, "<=");
}

void PrintingVisitor::visit(GeqExpression* geq_expression) {
    visit_binary_op(geq_expression, ">=");
}

void PrintingVisitor::visit(ShlExpression* shl_expression) {
    visit_binary_op(shl_expression, "<<");
}

void PrintingVisitor::visit(ShrExpression* shr_expression) {
    visit_binary_op(shr_expression, ">>");
}

void PrintingVisitor::visit(AddExpression* add_expression) {
    visit_binary_op(add_expression, "+");
}

void PrintingVisitor::visit(SubExpression* sub_expression) {
    visit_binary_op(sub_expression, "-");
}

void PrintingVisitor::visit(MulExpression* mul_expression) {
    visit_binary_op(mul_expression, "*");
}

void PrintingVisitor::visit(DivExpression* div_expression) {
    visit_binary_op(div_expression, "/");
}

void PrintingVisitor::visit(ModExpression* mod_expression) {
    visit_binary_op(mod_expression, "%");
}

void PrintingVisitor::visit(IdentifierExpression* identifier_expression) {
    print_tabs();
    stream_ << "[id]: " << identifier_expression->identifier() << std::endl;
}

void PrintingVisitor::visit(ConstantExpression* constant_expression) {
    print_tabs();
    stream_ << "[const]: " << constant_expression->constant() << std::endl;
}

void PrintingVisitor::visit(StringExpression* string_expression) {
    print_tabs();
    stream_ << "[string]: " << string_expression->string() << std::endl;
}

template<class T>
void PrintingVisitor::visit_binary_op(T* op_expression, const std::string& op_string) {
    print_tabs();
    stream_ << "[op]: " << op_string << std::endl;
    tabs_++;
    auto left_expr = op_expression->left_expression();
    auto right_expr = op_expression->right_expression();
    left_expr->accept_visitor(this);
    right_expr->accept_visitor(this);
    tabs_--;
}

void PrintingVisitor::print_tabs() {
    for (size_t i = 0; i < tabs_; i++) {
        stream_ << "\t";
    }
}

}; // namespace nezoku
