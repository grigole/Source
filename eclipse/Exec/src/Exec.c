#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main( int argc, char** argv )
{
	pid_t	process;
	int		status;
	int		ret;

	// Fork
	process = fork();
	if ( process == -1 )
		handle_error( "execv" );

	if ( process != 0 )
	{
		// Wait for the child to terminate

		printf( "Waiting for child to terminate\n" );

		process = wait( &status );

		printf( "Child done\n" );

		exit( 0 );
	}

	// Execute ls
	char* args[] = { "/bin/ls", "-lF", NULL };

	printf( "Child running ls...\n" );

	ret = execv( "/bin/ls", args );
	if ( ret == -1 )
		handle_error( "execv" );
}
