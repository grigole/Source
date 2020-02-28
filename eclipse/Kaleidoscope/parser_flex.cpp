#include <cstdio>

extern "C" int yyparse( void );

int main( int argc, char** argv )
{
	yyparse();
}

extern "C" void yyerror (char const *s)
{
	fprintf( stderr, "%s\n", s );
}
