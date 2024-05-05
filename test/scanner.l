%{
    #include <cstdlib>
    #include <cstring>
    #include <iostream>
    #include <string>
    #include "parser.hpp"
%}

%option c++
%option noyywrap

%{
    int yyinput();
    void yyerror(const char* const message);
    void yycomment();
%}

OC [0-7]
DM [0-9]
NZ [1-9]
HX [a-fA-F0-9]
EP ([e][+-]?{DM}+)
LT [a-zA-Z_]
AP [a-zA-Z_0-9]
WS [ \t\v\n\f]
FS (_)?(f32|f64)
IS (_)?(u8|i8|u16|i16|u32|i32|u64|i64)
HP (0[xX])
ES (\\(['"\?\\abfnrtv]|x{HX}+))

%%

"//".*                  { /* consume // comment */ }
"/*"                    { yycomment(); }

"break"                 { return yy::parser::token::BREAK; }
"case"                  { return yy::parser::token::CASE; }
"char"                  { return yy::parser::token::CHAR; }
"const"                 { return yy::parser::token::CONST; }
"continue"              { return yy::parser::token::CONTINUE; }
"default"               { return yy::parser::token::DEFAULT; }
"do"                    { return yy::parser::token::DO; }
"else"                  { return yy::parser::token::ELSE; }
"enum"                  { return yy::parser::token::ENUM; }
"extern"                { return yy::parser::token::EXTERN; }
"for"                   { return yy::parser::token::FOR; }
"goto"                  { return yy::parser::token::GOTO; }
"bool"                  { return yy::parser::token::BOOL; }
"f32"                   { return yy::parser::token::FLOAT_32; }
"f64"                   { return yy::parser::token::FLOAT_64; }
"if"                    { return yy::parser::token::IF; }
"i8"                    { return yy::parser::token::INT_8; }
"u8"                    { return yy::parser::token::UINT_8; }
"i16"                   { return yy::parser::token::INT_16; }
"u16"                   { return yy::parser::token::UINT_16; }
"i32"                   { return yy::parser::token::INT_32; }
"u32"                   { return yy::parser::token::UINT_32; }
"i64"                   { return yy::parser::token::INT_64; }
"u64"                   { return yy::parser::token::UINT_64; }
"return"                { return yy::parser::token::RETURN; }
"sizeof"                { return yy::parser::token::SIZEOF; }
"static"                { return yy::parser::token::STATIC; }
"struct"                { return yy::parser::token::STRUCT; }
"switch"                { return yy::parser::token::SWITCH; }
"typedef"               { return yy::parser::token::TYPEDEF; }
"union"                 { return yy::parser::token::UNION; }
"unit"                  { return yy::parser::token::UNIT; }
"while"                 { return yy::parser::token::WHILE; }

">>="                   { return yy::parser::token::RIGHT_ASSIGN; }
"<<="                   { return yy::parser::token::LEFT_ASSIGN; }
"+="                    { return yy::parser::token::ADD_ASSIGN; }
"-="                    { return yy::parser::token::SUB_ASSIGN; }
"*="                    { return yy::parser::token::MUL_ASSIGN; }
"/="                    { return yy::parser::token::DIV_ASSIGN; }
"%="                    { return yy::parser::token::MOD_ASSIGN; }
"&="                    { return yy::parser::token::AND_ASSIGN; }
"^="                    { return yy::parser::token::XOR_ASSIGN; }
"|="                    { return yy::parser::token::OR_ASSIGN; }
">>"                    { return yy::parser::token::RIGHT_OP; }
"<<"                    { return yy::parser::token::LEFT_OP; }
"++"                    { return yy::parser::token::INC_OP; }
"--"                    { return yy::parser::token::DEC_OP; }
"->"                    { return yy::parser::token::PTR_OP; }
"&&"                    { return yy::parser::token::LAND_OP; }
"||"                    { return yy::parser::token::LOR_OP; }
"<="                    { return yy::parser::token::LE_OP; }
">="                    { return yy::parser::token::GE_OP; }
"=="                    { return yy::parser::token::EQ_OP; }
"!="                    { return yy::parser::token::NE_OP; }
";"                     { return yy::parser::token::SEMICOLON; }
("{"|"<%")              { return yy::parser::token::LBRACE; }
("}"|"%>")              { return yy::parser::token::RBRACE; }
","                     { return yy::parser::token::COMA; }
":"                     { return yy::parser::token::COLON; }
"="                     { return yy::parser::token::ASSIGN; }
"("                     { return yy::parser::token::LROUND; }
")"                     { return yy::parser::token::RROUND; }
("["|"<:")              { return yy::parser::token::LSQUARE; }
("]"|":>")              { return yy::parser::token::RSQUARE; }
"."                     { return yy::parser::token::PERIOD; }
"!"                     { return yy::parser::token::LNOT_OP; }
"&"                     { return yy::parser::token::AND_OP; }
"|"                     { return yy::parser::token::OR_OP; }
"~"                     { return yy::parser::token::NOT_OP; }
"-"                     { return yy::parser::token::SUB_OP; }
"+"                     { return yy::parser::token::ADD_OP; }
"*"                     { return yy::parser::token::ASTERISK_OP; }
"/"                     { return yy::parser::token::DIV_OP; }
"%"                     { return yy::parser::token::MOD_OP; }
"<"                     { return yy::parser::token::LESS_OP; }
">"                     { return yy::parser::token::GREATER_OP; }
"^"                     { return yy::parser::token::XOR_OP; }
"?"                     { return yy::parser::token::QUESTION_OP; }

{HP}{HX}+{IS}?                  { return yy::parser::token::INT_CONST; }    
{NZ}{DM}*{IS}?                  { return yy::parser::token::INT_CONST; }
"0"{OC}*{IS}?                   { return yy::parser::token::INT_CONST; }
"'"([^'\\\n]|{ES})+"'"          { return yy::parser::token::INT_CONST; }
{DM}+{EP}{FS}?				    { return yy::parser::token::FLOAT_CONST; }
{DM}*"."{DM}+{EP}?{FS}?         { return yy::parser::token::FLOAT_CONST; }
{DM}+"."{EP}?{FS}?			    { return yy::parser::token::FLOAT_CONST; }
(\"([^"\\\n]|{ES})*\"{WS}*)+    { return yy::parser::token::STRING_LITERAL; }

{WS}+       { /* whitespace separates tokens */ }
.			{ yyerror("Unknown symbol."); }

%%

void yycomment() {
    int symbol = 0;

    while (true) {
        while ((symbol = yyinput()) != '*' && symbol != EOF ) { }

        if (symbol == '*') {
            while ((symbol = yyinput()) == '*') {}

            if (symbol == '/') {
                break;
            }
        }

        if (symbol == EOF) {
            yyerror("Unterminated comment.");
            break;
        }
    }
}
