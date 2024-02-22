#include <stdio.h>
#include <stdlib.h>

#define     SMALL_SIZE      128
#define     LARGE_SIZE      128000

int main()
{
    printf( "malloc debugging\n");

    // Allocate a small block
    char* smallBlock = malloc( SMALL_SIZE );

    // Allocate a small block
    char* largeBlock = malloc( LARGE_SIZE );

    // Free blocks
    free( smallBlock );

    // Access smallBlock after free()

    char* badPtr1 = smallBlock;
    *badPtr1 = '\0';

    free( largeBlock );

    // Access largeBlock after free()

    char* badPtr2 = largeBlock;
    *badPtr2 = '\0';

    return 0;
}
