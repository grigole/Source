%{

// Give Flex the prototype of yylex we want ...
# define YY_DECL \
  yy::parser::symbol_type yylex (driver& drv)
// ... and declare it for the parser's sake.
YY_DECL;

%}

%require "3.1"
%language "c++"
%output  "bison.cpp"
%defines "bison.h"

%union
{
   int intVal;
   char* stringVal;
}

%token TOK_DEF			"def"
%token TOK_EXTERN   	"extern"
%token TOK_NUMBER
%token TOK_IDENTIFIER

/* Precedence (increasing) and associativity:
   a+b+c is (a+b)+c: left associativity
   a+b*c is a+(b*c): the precedence of "*" is higher than that of "+". */
// %left "+"
// %left "*"

%%

extern : TOK_EXTERN name args
			{			
			} 

def : TOK_DEF name args
			{			
			} 

name : TOK_IDENTIFIER
			{
			}

args : TOK_IDENTIFIER args
			{
			}

args : TOK_IDENTIFIER
			{
			}

    ;

%%