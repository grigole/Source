#include <cstdio>

int main( int argc, char** argv )
{
}

extern "C" void yyerror (char const *s)
{
	fprintf( stderr, "%s\n", s );
}
