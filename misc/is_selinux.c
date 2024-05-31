#include <stdio.h>
#include <stdlib.h>

#include <selinux/selinux.h>

int main()
{
	printf( "%d\n", is_selinux_enabled() );

	return 0;
}
