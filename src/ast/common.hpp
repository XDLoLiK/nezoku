#ifndef COMMON_HPP
#define COMMON_HPP

namespace nezoku {

class Visitor;

class TranslationUnit;
class FunctionDefinition;
class Declaration;

class Statement;
class CompoundStatement;
class ExpressionStatement;
class ReturnStatement;
class ContinueStatement;
class BreakStatement;
class SelectionStatement;
class IterationStatement;

class Expression;
class CommaExpression;
class AssignmentExpression;
class LorExpression;
class LandExpression;
class OrExpression;
class XorExpression;
class AndExpression;
class EqExpression;
class NeqExpression;
class LessExpression;
class GreaterExpression;
class LeqExpression;
class GeqExpression;
class ShlExpression;
class ShrExpression;
class AddExpression;
class SubExpression;
class MulExpression;
class DivExpression;
class ModExpression;
class IdentifierExpression;
class ConstantExpression;
class StringExpression;

}; // namespace nezoku

#endif // COMMON_HPP
