%{

#include "bison.h"
#include <stdio.h>

// #define YY_DECL int yylex( yy::KaleidParser::semantic_type* const lval, \
//	yy::KaleidParser::location_type* location, KaleidDriver& driver )

%}

digit         [0-9]
letter        [a-zA-Z]

%%

"def"					{ return TOK_DEF; }
"extern"				{ return TOK_EXTERN; }

[digit]+"."?+[digit]+	{ return TOK_NUMBER; }
[letter][{letter}0-9]*	{ return TOK_IDENTIFIER; }

%%

int yywrap(void){return 1;}
