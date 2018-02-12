#include <stdio.h>
#include <stdlib.h>

long int do_sum( long int start, long int end )
{
    long int	x;
    long int	sum;

#pragma omp parallel for
    for ( x = start; x < end; x++)
    {
        	sum += x;
    }

    return sum;
}

int main( int argc, char** argv )
{
     // Validate the arguments

     if ( argc != 2 )
     {
         fprintf( stderr, "use: %s <sum_to>\n", argv[0] );

         exit( -1 );
     }

     // Parse the arguments

     long int nMax = atol( argv[1] );
     if ( nMax < 0 )
     {
             fprintf( stderr, "sum_to must be > 0\n" );

             exit( -2 );
     }

     long int result = do_sum( 0, nMax );

     printf( "result = %ld\n", result );
}
