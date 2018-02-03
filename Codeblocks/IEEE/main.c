#include <stdio.h>
#include <stdlib.h>
#include <ieee754.h>

void print_double( double dbl )
{
    union ieee754_double  ieee_dbl;
    ieee_dbl.d = dbl;

    printf( "double    : %f\n", ieee_dbl.d );
    printf( "negative  : %d\n", ieee_dbl.ieee.negative );
    printf( "mantissa0 : %0x\n", ieee_dbl.ieee.mantissa0 );
    printf( "mantissa1 : %0x\n", ieee_dbl.ieee.mantissa1 );
    printf( "exponent  : %d\n\n", ieee_dbl.ieee.exponent );
}

int main()
{
    printf("IEEE Demo!\n");

    print_double( 1.0 );
    print_double( 2.0 );
    print_double( 3.0 );
    print_double( 1.0/3.0 );
    print_double( -2.0/3.0 );

    return 0;
}
