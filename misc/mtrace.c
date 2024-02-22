#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>

int main( void )
{
	mtrace();

	char *ptr1 = malloc( 1024 );
	char *ptr2 = malloc( 8192 );

	free( ptr1 );
	free( ptr2 );

	muntrace();

	return 0;
}
