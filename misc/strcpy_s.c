#include <stdio.h>
#include <string.h>

int main( int argc, char* argv[] )
{
	char copy[256];

	strcpy_s( copy, "One" );

	printf( "copy = \"%s\"\n", copy );

	return 0;
}
