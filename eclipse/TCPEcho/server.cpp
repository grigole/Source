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
	log4c_init();
	mycat = log4c_category_get( "tcp_server.log" );
	int	tcp_socket, 	st;
	struct addrinfo 	addr, *result;
	struct sockaddr 	sa;

	log4c_init();
	mycat = log4c_category_get( "tcp_server.log" );

	// Read the config file
	tcpConfig config( "tcp_server.cfg" );

	// Listen on the port

	/* Obtain address(es) matching host/port */

	memset( &addr, 0, sizeof(struct addrinfo) );
	addr.ai_family = AF_UNSPEC;			/* Allow IPv4 only for now */
	addr.ai_socktype = SOCK_STREAM;		/* Datagram socket */
	addr.ai_flags = AI_PASSIVE;			/* for listening */
	addr.ai_protocol = 0;           	/* Any protocol */

	printf( "service is %s\n", config.get_service() );
	st = getaddrinfo( NULL, config.get_service(), &addr, &result );
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

	for ( rp = result; rp != NULL; rp = rp->ai_next )
	{
		printf( "\n", rp );
		print_addrinfo( rp );

		printf( "Opening socket - " );

		tcp_socket = socket( rp->ai_family, rp->ai_socktype, rp->ai_protocol );
        if ( tcp_socket == -1 )
        {
        	printf( "can't open socket - %s\n", strerror( st ) );

        	continue;
        }

        st = bind( tcp_socket, rp->ai_addr, rp->ai_addrlen);
        if ( st == 0 )
        {
        	printf( "bound to socket\n" );

        	break;                  /* Success */
        }

    	printf( "bind failed - %s\n", strerror( st ) );

    	close( tcp_socket );
	}

    if ( rp == NULL )
    {               /* No address succeeded */
        fprintf( stderr, "Could not bind to a socket\n" );

        exit( EXIT_FAILURE );
    }

    // Listen for connections

    printf( "Listening...\n" );

    st = listen( tcp_socket, 1 );
    if ( st == -1 )
    {
        fprintf( stderr, "listen() failed - %s\n", strerror( st ) );

        freeaddrinfo( result );
    	log4c_fini();

        exit( EXIT_FAILURE );
    }

    printf( "Sleeping for 15 seconds... " );
    fflush( stdout );

    sleep( 15 );

    printf( "done\n" );

	freeaddrinfo( result );

	log4c_fini();

	return 0;
}



