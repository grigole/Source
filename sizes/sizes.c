#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main( int argc, char* argv[] )
{
	printf( "Data Sizes\n" );
	printf( "==========\n" );

	printf( "char        : %ld\n", sizeof( char ) );
	printf( "short       : %ld\n", sizeof( short ) );
	printf( "int         : %ld\n", sizeof( int ) );
	printf( "long        : %ld\n", sizeof( long ) );
	printf( "long long   : %ld\n", sizeof( long long ) );
	printf( "float       : %ld\n", sizeof( float ) );
	printf( "double      : %ld\n", sizeof( double ) );
	printf( "long double : %ld\n", sizeof( long double ) );
	printf( "_Decimal32  : %ld\n", sizeof( _Decimal32 ) );
	printf( "_Decimal64  : %ld\n", sizeof( _Decimal64 ) );
	printf( "_Decimal128 : %ld\n", sizeof( _Decimal128 ) );
	printf( "int8_t      : %ld\n", sizeof( int8_t ) );
	printf( "int16_t     : %ld\n", sizeof( int16_t ) );
	printf( "int32_t     : %ld\n", sizeof( int32_t ) );
	printf( "int64_t     : %ld\n", sizeof( int64_t ) );
	printf( "size_t      : %ld\n", sizeof( size_t ) );
	printf( "pid_t       : %ld\n", sizeof( pid_t ) );
	printf( "void *      : %ld\n", sizeof( void * ) );
	printf( "char *      : %ld\n", sizeof( char * ) );

	return 0;
}

// vim: set ts=4:
