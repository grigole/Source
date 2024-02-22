#include <stdio.h>
#include <stdarg.h>
#include <mpfr.h>

int main( void )
{
	// First some palin-old long variables
	
	long x = 1000000000;
	long y = 9223372036854775807L;
	long z = 110223372036854775807L;
	mpfr_t xx;

	printf( "x  = %ld\n", x );
	printf( "y  = %ld\n", y );
	printf( "z  = %ld\n", z );

	// Then some fancy mpfr variables!
	
	mpfr_init2( xx, 200 );

	mpfr_set_str( xx, "1000000000000000000000000", 10, MPFR_RNDN );

	printf( "xx = " );
	mpfr_out_str( stdout, 10, 0, xx, MPFR_RNDD);
	printf( "\n" );

	return 0;
}
