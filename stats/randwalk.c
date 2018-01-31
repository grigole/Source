//
//	randwalk.c - determine distributon of outcomes
//				 from a random walk
//

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	long long x, nHeads = 0, nTails = 0;

	srand( time( NULL ) );

	for ( x = 0; x < 1000000000; x++ )
	{
		long res = rand() % 100;

		if ( res < 50 )
			nTails++;
		else
			nHeads++;
/*
		if ( x > 0 && (x % 1000000) == 0 )
		{
			printf( "%ld : Heads %lf, tails %lf\n",
				x, nHeads / 1000000.0 * 100, nTails / 1000000.0 * 100 );

			nHeads = 0; nTails = 0;
		}
*/
	}

	printf( "%ld : Heads %lf, tails %lf\n",
		x, (double)nHeads / x * 100, (double)nTails / x * 100 );
	
	return 0;
}
