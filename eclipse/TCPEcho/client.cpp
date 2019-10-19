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
#include "protocol.h"

log4c_category_t* mycat = NULL;

int main( int argc, char **argv )
{
	int	tcp_socket, 	st;
	struct addrinfo 	addr, *result;

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
//		print_addrinfo( rp );

		printf( "Opening socket - " );

		tcp_socket = socket( rp->ai_family, rp->ai_socktype, rp->ai_protocol );
        if ( tcp_socket == -1 )
        {
        	printf( "can't open socket - %d (%s)\n", errno, strerror( errno ) );

        	continue;
        }

		printf( "success\n" );
		printf( "Connecting - " );

        unsigned int	saSize = sizeof( struct sockaddr_storage );

        st = connect( tcp_socket, rp->ai_addr, saSize );
        if ( st == 0 )
        {
        	printf( "conected\n" );

        	break;
        }

    	printf( "can't connect - %d (%s)\n", errno, strerror( errno ) );

    	close( tcp_socket );
	}

    if ( rp == NULL )
    {               /* No address succeeded */
        fprintf( stderr, "Could not connect to server\n" );

        exit( EXIT_FAILURE );
    }

	freeaddrinfo( result );

    // Send one packet
    struct tcpecho    outpkt, inpkt;

    printf( "Sending packet - " );
    fflush( stdout );

    strcpy( outpkt.msg, "First message" );
    outpkt.size = strlen( outpkt.msg ) + 1;

    st = write( tcp_socket, &outpkt, sizeof( outpkt ) );
    if ( st == -1 )
    {
    	fprintf( stderr, "write() failed - %d (%s)\n", errno, strerror( errno ) );
    }
    else
    {
    	printf( "OK\n" );

    	printf( "Waiting for reply - " );
    	fflush( stdout );

    	// Receive one packet

    	st = read( tcp_socket, &inpkt, sizeof( inpkt ) );
        if ( st == -1 )
        {
        	fprintf( stderr, "read() failed - %d (%s)\n", errno, strerror( errno ) );
        }
        else
        {
        	printf( "OK\n" );

        	printf( "inpkt.size = %d\n", inpkt.size );
        	printf( "inpkt.msg  = %s\n", inpkt.msg );
        }
    }

    close( tcp_socket );

	// log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "argc = %d", argc );

	log4c_fini();

	return EXIT_SUCCESS;
}
