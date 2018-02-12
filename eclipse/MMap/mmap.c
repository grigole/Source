#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main( int argc, char** argv )
{
	int				fd;
	struct stat		sb;
	void*			file;
	Elf64_Ehdr*		data;

	fd = open( "/bin/bash", O_RDONLY );
	if ( fd == -1 )
		handle_error( "open" );

	 if (fstat( fd, &sb ) == -1)           /* To obtain file size */
		 handle_error( "fstat" );

	file = mmap( NULL,
				 sb.st_size,
				 PROT_READ,
				 MAP_PRIVATE,
				 fd,
				 0
			 );
	if ( file == MAP_FAILED )
		 handle_error( "mmap" );

	data = (Elf64_Ehdr *)file;

	printf( "e_ident   : " );
	int x;
	for ( x = 0; x < EI_NIDENT; x++ )
	{
		printf( "%02x ", data->e_ident[x] );
	}
	printf( "\n" );

	printf( "e_type    : %d\n", data->e_type );
	printf( "e_machine : %d\n", data->e_machine );
	printf( "e_version : %d\n", data->e_version );

	munmap( file, sb.st_size );
	close( fd );
}
