#include <stdio.h>
#include <sys/auxv.h>

int main( void )
{
	unsigned long hdr = getauxval( AT_SYSINFO_EHDR );

	printf( "hdr = 0x%016lx\n", hdr );

	return 0;
}
