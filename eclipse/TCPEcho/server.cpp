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
#include <signal.h>

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
#include "protocol.h"

log4c_category_t* mycat = NULL;

static int		inFd = 0, tcp_socket = 0;

// Signal handler

void handler( int )
{
	printf( "ctrl-c received\n" );

	if ( inFd != 0 )
	{
		close( inFd );
		printf( "closed communication socket\n" );
	}
	if ( tcp_socket != 0 )
	{
		close( tcp_socket );
		printf( "Closed listening socket\n" );
	}

	exit( EXIT_FAILURE );
}

int main( int argc, char **argv )
{
	log4c_init();
	mycat = log4c_category_get( "tcp_server.log" );

	int					st;
	struct addrinfo 	addr, *result;
	struct sockaddr 	sa;

	log4c_init();
	mycat = log4c_category_get( "tcp_server.log" );

	// Handle ctrl-c
	signal( SIGINT, handler );

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
        	fprintf( stderr, "can't open socket - %d (%s)\n", errno, strerror( errno ) );

        	continue;
        }

        // Handle partially closed sockets
        int enable = 1;
        st = setsockopt( tcp_socket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof( int ) );
        if ( st == -1 )
        {
        	fprintf( stderr, "setsockopt() failed - %d (%s)\n", errno, strerror( errno ) );

        	close( tcp_socket );
        	exit( EXIT_FAILURE );
        }

        st = bind( tcp_socket, rp->ai_addr, rp->ai_addrlen);
        if ( st == 0 )
        {
        	printf( "bound to socket\n" );

        	break;                  /* Success */
        }

    	fprintf( stderr, "bind failed - %d (%s)\n", errno, strerror( errno ) );

    	close( tcp_socket );
	}

    if ( rp == NULL )
    {               /* No address succeeded */
        fprintf( stderr, "Could not bind to a socket\n" );

        exit( EXIT_FAILURE );
    }

    // Set socket as listening

    printf( "Listening - " );

    st = listen( tcp_socket, 1 );
    if ( st == -1 )
    {
        fprintf( stderr, "listen() failed - %d (%s)\n", errno, strerror( errno ) );

        freeaddrinfo( result );
    	log4c_fini();

        exit( EXIT_FAILURE );
    }

    printf( "OK\n" );

    // Listen for connections

    unsigned int				saSize = sizeof( struct sockaddr_storage );

    while ( 1 )
    {
    	printf( "Waiting for connection - " );
    	fflush( stdout );

    	inFd = accept( tcp_socket, &sa, &saSize );
		if ( inFd == -1 )
		{
			printf( "accept() failed - %s\n", strerror( errno ) );

			freeaddrinfo( result );
			log4c_fini();

			exit( EXIT_FAILURE );
		}

		printf( "connection established\n");

		printf( "Reading packet - " );
		fflush( stdout );

		struct tcpecho	pkt;
		bzero( &pkt, sizeof( pkt ) );

		st = read( inFd, &pkt, sizeof( pkt ) );
		if ( st == -1 )
		{
			printf( "read() failed - %d (%s)\n", errno, strerror( errno ) );

			continue;
		}

		printf( "OK\n" );

		printf( "Received %d bytes\n", st );

		if ( st > 0 )
		{
			// Reply

        	printf( "pkt.size = %d\n", pkt.size );
        	printf( "pkt.msg  = %s\n", pkt.msg );

			printf( "Echoing packet - " );
			fflush( stdout );

			st = write( inFd, &pkt, sizeof( pkt ) );
			if ( st == -1 )
			{
				printf( "write() failed - %d (%s)\n", errno, strerror( errno ) );

				close( inFd );

				continue;
			}

			printf( "OK\n" );
		} /* not EOF */
		else
			printf( "EOF\n" );

		close( inFd );
		inFd = 0;
    } // while ( 1 )

    printf( "Done\n" );

	freeaddrinfo( result );

	log4c_fini();

	return 0;
}
