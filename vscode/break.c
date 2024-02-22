#include <stdio.h>
#include <unistd.h>

int main()
{
	printf( "%p\n", sbrk( 0 ) );
}
