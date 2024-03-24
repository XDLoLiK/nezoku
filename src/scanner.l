%{
    #include <cstdlib>
    #include <cstring>
    #include <iostream>
    #include <string>

    #include "parser.tab.hh"
%}

%option c++
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
WS [ \t\v\n\f]
FS ((_)?(f32|f64))
IS ((_)?(u8|i8|u16|i16|u32|i32|u64|i64))
HP (0[xX])
ES (\\(['"\?\\abfnrtv]|x{HX}+))

%%

"//".*                  { /* consume // comment */ }
"/*"                    {
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
                                    LexerError("Unterminated comment.");
                                    break;
                                }
                            }
                        }

"break"                 { return yy::parser::token::BREAK_KW; }
"char"                  { return yy::parser::token::CHAR_T; }
"const"                 { return yy::parser::token::CONST_KW; }
"continue"              { return yy::parser::token::CONTINUE_KW; }
"else"                  { return yy::parser::token::ELSE_KW; }
"enum"                  { return yy::parser::token::ENUM_KW; }
"for"                   { return yy::parser::token::FOR_KW; }
"bool"                  { return yy::parser::token::BOOL_T; }
"f32"                   { return yy::parser::token::FLOAT_32_T; }
"f64"                   { return yy::parser::token::FLOAT_64_T; }
"if"                    { return yy::parser::token::IF_KW; }
"i8"                    { return yy::parser::token::INT_8_T; }
"u8"                    { return yy::parser::token::UINT_8_T; }
"i16"                   { return yy::parser::token::INT_16_T; }
"u16"                   { return yy::parser::token::UINT_16_T; }
"i32"                   { return yy::parser::token::INT_32_T; }
"u32"                   { return yy::parser::token::UINT_32_T; }
"i64"                   { return yy::parser::token::INT_64_T; }
"u64"                   { return yy::parser::token::UINT_64_T; }
"return"                { return yy::parser::token::RETURN_KW; }
"sizeof"                { return yy::parser::token::SIZEOF_KW; }
"while"                 { return yy::parser::token::WHILE_KW; }

">>="                   { return yy::parser::token::SHR_ASSIGN; }
"<<="                   { return yy::parser::token::SHL_ASSIGN; }
"+="                    { return yy::parser::token::ADD_ASSIGN; }
"-="                    { return yy::parser::token::SUB_ASSIGN; }
"*="                    { return yy::parser::token::MUL_ASSIGN; }
"/="                    { return yy::parser::token::DIV_ASSIGN; }
"%="                    { return yy::parser::token::MOD_ASSIGN; }
"&="                    { return yy::parser::token::AND_ASSIGN; }
"^="                    { return yy::parser::token::XOR_ASSIGN; }
"|="                    { return yy::parser::token::OR_ASSIGN; }
">>"                    { return yy::parser::token::SHR_OP; }
"<<"                    { return yy::parser::token::SHL_OP; }
"++"                    { return yy::parser::token::INC_OP; }
"--"                    { return yy::parser::token::DEC_OP; }
"->"                    { return yy::parser::token::PTR_OP; }
"&&"                    { return yy::parser::token::LAND_OP; }
"||"                    { return yy::parser::token::LOR_OP; }
"<="                    { return yy::parser::token::LEQ_OP; }
">="                    { return yy::parser::token::GEQ_OP; }
"=="                    { return yy::parser::token::EQ_OP; }
"!="                    { return yy::parser::token::NEQ_OP; }

{LT}{AP}*                       { return yy::parser::token::IDENTIFIER; }
{HP}{HX}+{IS}?                  { return yy::parser::token::CONSTANT; }    
{NZ}{DM}*{IS}?                  { return yy::parser::token::CONSTANT; }
"0"{OC}*{IS}?                   { return yy::parser::token::CONSTANT; }
"'"([^'\\\n]|{ES})+"'"          { return yy::parser::token::CONSTANT; }
{DM}+{EP}{FS}?				    { return yy::parser::token::CONSTANT; }
{DM}*"."{DM}+{EP}?{FS}?         { return yy::parser::token::CONSTANT; }
{DM}+"."{EP}?{FS}?			    { return yy::parser::token::CONSTANT; }
(\"([^"\\\n]|{ES})*\"{WS}*)+    { return yy::parser::token::STRING_LITERAL; }

{WS}+       { /* whitespace separates tokens */ }
.			{ LexerError("Unknown symbol."); }

%%
