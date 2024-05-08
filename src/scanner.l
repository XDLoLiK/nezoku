%{
    #include <cstdlib>
    #include <cstring>
    #include <iostream>
    #include <string>

    #include "driver.hpp"
    #include "parser.hpp"
%}

%option c++
%option yyclass="Scanner"
%option noyywrap
%option noinput
%option nounput
%option batch
%option debug

OC [0-7]
DM [0-9]
NZ [1-9]
HX [a-fA-F0-9]
EP ([e][+-]?{DM}+)
LT [a-zA-Z_]
AP [a-zA-Z_0-9]
WS [ \t\v\f]
FS ((_)?(f32|f64))
IS ((_)?(u8|i8|u16|i16|u32|i32|u64|i64))
HP (0[xX])
ES (\\(['"\?\\abfnrtv]|x{HX}+))

%{
    // Code run every time a pattern is matched.
    #define YY_USER_ACTION  loc.columns(yyleng);
%}

%%

%{
    // Code run every time yylex is invoked.
    yy::location& loc = driver.location;
    loc.step();
%}

"//".*                  { /* consume // comment */ }
"/*"                    {
                            int symbol = 0;

                            while (true) {
                                while ((symbol = yyinput()) != '*' && symbol != EOF ) {}

                                if (symbol == '*') {
                                    while ((symbol = yyinput()) == '*') {}

                                    if (symbol == '/') {
                                        break;
                                    }
                                }

                                if (symbol == EOF) {
                                    throw yy::parser::syntax_error(loc, "unterminated comment: " + std::string(yytext));
                                    break;
                                }
                            }
                        }

"break"                 { return yy::parser::make_BREAK_KW(loc); }
"char"                  { return yy::parser::make_CHAR_T(loc); }
"continue"              { return yy::parser::make_CONTINUE_KW(loc); }
"else"                  { return yy::parser::make_ELSE_KW(loc); }
"for"                   { return yy::parser::make_FOR_KW(loc); }
"bool"                  { return yy::parser::make_BOOL_T(loc); }
"f32"                   { return yy::parser::make_FLOAT_32_T(loc); }
"f64"                   { return yy::parser::make_FLOAT_64_T(loc); }
"if"                    { return yy::parser::make_IF_KW(loc); }
"i8"                    { return yy::parser::make_INT_8_T(loc); }
"u8"                    { return yy::parser::make_UINT_8_T(loc); }
"i16"                   { return yy::parser::make_INT_16_T(loc); }
"u16"                   { return yy::parser::make_UINT_16_T(loc); }
"i32"                   { return yy::parser::make_INT_32_T(loc); }
"u32"                   { return yy::parser::make_UINT_32_T(loc); }
"i64"                   { return yy::parser::make_INT_64_T(loc); }
"u64"                   { return yy::parser::make_UINT_64_T(loc); }
"return"                { return yy::parser::make_RETURN_KW(loc); }
"while"                 { return yy::parser::make_WHILE_KW(loc); }

">>="                   { return yy::parser::make_SHR_ASSIGN(loc); }
"<<="                   { return yy::parser::make_SHL_ASSIGN(loc); }
"+="                    { return yy::parser::make_ADD_ASSIGN(loc); }
"-="                    { return yy::parser::make_SUB_ASSIGN(loc); }
"*="                    { return yy::parser::make_MUL_ASSIGN(loc); }
"/="                    { return yy::parser::make_DIV_ASSIGN(loc); }
"%="                    { return yy::parser::make_MOD_ASSIGN(loc); }
"&="                    { return yy::parser::make_AND_ASSIGN(loc); }
"^="                    { return yy::parser::make_XOR_ASSIGN(loc); }
"|="                    { return yy::parser::make_OR_ASSIGN(loc); }
">>"                    { return yy::parser::make_SHR(loc); }
"<<"                    { return yy::parser::make_SHL(loc); }
"&&"                    { return yy::parser::make_LAND(loc); }
"||"                    { return yy::parser::make_LOR(loc); }
"<="                    { return yy::parser::make_LEQ(loc); }
">="                    { return yy::parser::make_GEQ(loc); }
"=="                    { return yy::parser::make_EQ(loc); }
"!="                    { return yy::parser::make_NEQ(loc); }

"|"                    { return yy::parser::make_OR(loc); }
"^"                    { return yy::parser::make_XOR(loc); }
"&"                    { return yy::parser::make_AND(loc); }
"<"                    { return yy::parser::make_LESS(loc); }
">"                    { return yy::parser::make_GREATER(loc); }
"+"                    { return yy::parser::make_ADD(loc); }
"-"                    { return yy::parser::make_SUB(loc); }
"*"                    { return yy::parser::make_MUL(loc); }
"/"                    { return yy::parser::make_DIV(loc); }
"%"                    { return yy::parser::make_MOD(loc); }
";"                    { return yy::parser::make_SEMICOLON(loc); }
"="                    { return yy::parser::make_ASSIGN(loc); }
"("                    { return yy::parser::make_LPAREN(loc); }
")"                    { return yy::parser::make_RPAREN(loc); }
","                    { return yy::parser::make_COMA(loc); }
"{"                    { return yy::parser::make_LBRACKET(loc); }
"}"                    { return yy::parser::make_RBRACKET(loc); }

{LT}{AP}*                           { return yy::parser::make_IDENTIFIER(yytext, loc); }
{HP}{HX}+{IS}?                      { return yy::parser::make_CONSTANT(yytext, loc); }    
{NZ}{DM}*{IS}?                      { return yy::parser::make_CONSTANT(yytext, loc); }
"0"{OC}*{IS}?                       { return yy::parser::make_CONSTANT(yytext, loc); }
"'"([^'\\\n]|{ES})+"'"              { return yy::parser::make_CONSTANT(yytext, loc); }
{DM}+{EP}{FS}?				        { return yy::parser::make_CONSTANT(yytext, loc); }
{DM}*"."{DM}+{EP}?{FS}?             { return yy::parser::make_CONSTANT(yytext, loc); }
{DM}+"."{EP}?{FS}?			        { return yy::parser::make_CONSTANT(yytext, loc); }
(\"([^"\\\n]|{ES})*\"({WS}|\n)*)+   { return yy::parser::make_STRING_LITERAL(yytext, loc); }

{WS}+       { loc.step(); }
\n+         {
                loc.lines(yyleng);
                loc.step();
            }
.			{ throw yy::parser::syntax_error(loc, "unknown symbol: " + std::string(yytext)); }
<<EOF>>     { return yy::parser::make_END(loc); }

%%
