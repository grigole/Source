#include <stdio.h>

main()
{
	long sum = 0;
	long x;

	for ( x = 0; x < 1000000; x++ )
	{
		sum += x;
	}

	printf( "sum = %ld\n", sum );
}
