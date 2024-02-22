#include <stdio.h>
#include <stdarg.h>
#include <mpfr.h>

int main( void )
{
	printf( "MPFR_PREC_MIN = %d bits\n", MPFR_PREC_MIN );
	printf( "MPFR_PREC_MAX = %ld bits (%ld megabytes)\n", MPFR_PREC_MAX, MPFR_PREC_MAX/8/1024/1024 );

	return 0;
}
