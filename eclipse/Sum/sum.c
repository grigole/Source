#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <pthread.h>

typedef struct sumdata {
	long int	start;
	long int	end;
	long int	result;
} sumdata_t;

void* do_sum( void *pData )
{
	sumdata_t*	data = (sumdata_t *)pData;
	long int 	x;

	data->result = 0;
	for ( x = data->start; x < data->end; x++)
	{
		data->result += x;
	}

	return NULL;
}

int main( int argc, char** argv )
{
	// Validate the arguments

	if ( argc != 3 )
	{
		fprintf( stderr, "use: %s <sum_to> <threads>", argv[0] );

		exit( -1 );
	}

	// Parse the arguments

	long int nMax = atol( argv[1] );
	if ( nMax < 0 )
	{
		fprintf( stderr, "sum_to must be > 0\n" );

		exit( -2 );
	}

	int nThreads = atol( argv[2] );
	if ( nThreads < 1 || nThreads > 8 )
	{
		fprintf( stderr, "threads must be between 1 and 8\n" );

		exit( -2 );
	}

	// Create the threads
	pthread_t	threads[ nThreads ];
	sumdata_t	data[ nThreads ];

	int x;
	long int incr = nMax / nThreads;
	printf( "incr = %ld\n", incr );
	for ( x = 0; x < nThreads; x++ )
	{
		data[x].start = incr * x;
		data[x].end = MIN( incr * (x+1), nMax );

		printf( "Thread %d: start %ld, end %ld\n",
				x, data[x].start, data[x].end );

		pthread_create(
						threads + x,
						NULL,
						&do_sum,
						(void *)(data + x)
					 );

	}

	// Collect the threads

	long int sum = 0;
	for ( x = 0; x < nThreads; x++ )
	{
		printf( "Collecting thread %d, start = %ld, end %ld\n",
				x,
				data[x].start,
				data[x].end );
		pthread_join( threads[x], NULL );
		printf( "result = %ld\n", data[x].result );
		sum += data[x].result;
	}

	printf( "sum = %ld\n", sum );
}
