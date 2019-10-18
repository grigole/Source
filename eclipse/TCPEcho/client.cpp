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

// Project
#include "config.h"
#include "util.h"

log4c_category_t* mycat = NULL;

int main( int argc, char **argv )
{
	int	tcp_socket, 	st;
	struct addrinfo 	addr, *result;
	struct sockaddr 	sa;

	log4c_init();
	mycat = log4c_category_get( "tcp_client.log" );

	// Read the config file
	tcpConfig config( "tcp_client.cfg" );

	// Connect to the server

	/* Obtain address(es) matching host/port */

	memset( &addr, 0, sizeof(struct addrinfo) );
	addr.ai_family = AF_UNSPEC;       /* Allow IPv4 only for now */
	addr.ai_socktype = SOCK_STREAM; /* Datagram socket */
	addr.ai_flags = 0;
	addr.ai_protocol = 0;           /* Any protocol */

	printf( "host is %s, service is %s\n", config.get_host(), config.get_service() );
	st = getaddrinfo( config.get_host(), config.get_service(), &addr, &result );
	if ( st != 0 )
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror( st ));

		exit( EXIT_FAILURE );
	}

	if ( result == NULL )
	{
		fprintf( stderr, "No connecton paths - done\n ");

		exit( EXIT_FAILURE );
	}

	struct addrinfo* rp;

	for (rp = result; rp != NULL; rp = rp->ai_next )
	{
		printf( "\n", rp );
		print_addrinfo( rp );
    }

#if 0
    tcp_socket = socket( AF_INET, SOCK_STREAM, 0 );
    if( tcp_socket == -1 )
    {
    	fprintf( stderr, "Unable to create socket - error %d\n", errno );

    	freeaddrinfo( result );
    	exit( EXIT_FAILURE );
    }

    fprintf( stdout, "Socket created successfully - %d\n", tcp_socket );
    close( tcp_socket );
#endif

    freeaddrinfo( result );

	// log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "argc = %d", argc );

	log4c_fini();

	return EXIT_SUCCESS;
}
