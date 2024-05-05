#ifndef SCANNER_HPP
#define SCANNER_HPP

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "parser.hpp"

#undef YY_DECL
#define YY_DECL yy::parser::symbol_type nezoku::Scanner::ScanToken()

namespace nezoku {

class Driver;

class Scanner: public yyFlexLexer {
public:
    Scanner(Driver& parser);
	~Scanner() final;

	yy::parser::symbol_type ScanToken();

private:
    Driver& driver;
};

}; // namespace nezoku

#endif // SCANNER_HPP
