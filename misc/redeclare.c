#include <stdio.h>

int main( int argc, char* argv[] )
{
	char *x = "Hello ";
	{
		int x = 3;

		printf( "x = %d\n", x );
	}
	return 0;
}
