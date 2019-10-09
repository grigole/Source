/*
 * server.cpp
 *
 *  Created on: Oct. 8, 2019
 *      Author: grigole
 */

// Standard
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

// Logging
#include <log4c.h>

// TCP
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

log4c_category_t* mycat = NULL;

int main( int argc, char **argv )
{
	const char*			host = "localhost";
	const char*			port = "6543";
	int	tcp_socket, 	st;
	struct addrinfo 	addr, *result;

	log4c_init();
	mycat = log4c_category_get( "tcp_client.log" );

	// Connect to the server

	/* Obtain address(es) matching host/port */

	memset( &addr, 0, sizeof(struct addrinfo) );
	addr.ai_family = AF_INET;    /* Allow IPv4 only for now */
	addr.ai_socktype = SOCK_DGRAM; /* Datagram socket */
	addr.ai_flags = 0;
	addr.ai_protocol = 0;          /* Any protocol */

	st = getaddrinfo( host, port, &addr, &result );
	if ( st != 0 )
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror( st ));

		exit( EXIT_FAILURE );
	}

    tcp_socket = socket( AF_INET, SOCK_STREAM, 0 );
    if( tcp_socket == -1 )
    {
    	fprintf( stderr, "Unable to create socket - error %d\n", errno );

    	exit( EXIT_FAILURE );
    }

    fprintf( stdout, "Socket created successfully - %d\n", tcp_socket );
    close( tcp_socket );

	// log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "argc = %d", argc );

	log4c_fini();

	return EXIT_SUCCESS;
}
