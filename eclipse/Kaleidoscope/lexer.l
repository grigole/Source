%{

#include "bison.h"
#include <stdio.h>

// #define YY_DECL int yylex( yy::KaleidParser::semantic_type* const lval, \
//	yy::KaleidParser::location_type* location, KaleidDriver& driver )

%}

digit         [0-9]
letter        [a-zA-Z]

%%

[digit]+"."?+[digit]+	{ return TOK_NUMBER; }
[letter][{letter}0-9]*	{ return TOK_IDENTIFIER; }

"def"					{ return TOK_DEF; }
"extern"				{ return TOK_EXTERN; }

%%

int yywrap(void){return 1;}
