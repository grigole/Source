#include <stdio.h>

void main()
{
	long sum = 0;
	int x;

	printf( "Start...\n" );

	for ( x = 0; x < 10000; x++ )
	{
		sum += x;
	}

	printf( "Done\n" );
	printf( "sum = %d\n", sum );
}
