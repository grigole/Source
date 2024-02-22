#include <stdio.h>

int main( void )
{
	char name[256];

	gets( name );

	printf( "Your name is : %s\n", name );

	return 0;
}
