#include <stdio.h>
#include <stdlib.h>

int main( int argc, char** argv )
{
    printf( "Hello world!\n");

    if ( argc != 2 )
    {
        printf( "Wrong # of arguments\n" );

        exit( 1 );
    }
    exit( 0 );
}