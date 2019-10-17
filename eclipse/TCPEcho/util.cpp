/*
 * util.cpp
 *
 *  Created on: Oct. 10, 2019
 *      Author: grigole
 */

#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

// Show contents of a struct addrinfo
char* xlate_addr_family( int family, char* text )
{

	switch ( family )
	{
		case AF_INET:
			strcpy( text, "IP" );
			break;
		case AF_INET6:
			strcpy( text, "IPV6" );
			break;
		default:
			sprintf( text, "%d", family );
			break;
	}

	return text;
}

// Show contents of a struct addrinfo
void print_addrinfo( struct addrinfo* ad_info )
{
	char 	family[32];
	int		st;
	struct sockaddr* 		sa;
	char ip[INET6_ADDRSTRLEN];

	printf( "ad_info->ai_family          : %s\n", xlate_addr_family( ad_info->ai_family, family ) );
	printf( "ad_info->ai_addr->sa_family : %s\n", xlate_addr_family( ad_info->ai_addr->sa_family, family ) );

	sa = (struct sockaddr *)ad_info->ai_addr;

	printf( "ad_info->ai_socktype        : %d\n", ad_info->ai_socktype );
	printf( "ad_info->ai_protocol        : %d\n", ad_info->ai_protocol );
	printf( "ad_info->ai_flags           : %08x\n", ad_info->ai_flags );
	printf( "ad_info->ai_cannonname      : %s\n", ad_info->ai_canonname );

	switch ( ad_info->ai_family )
	{
		case AF_INET:
			struct sockaddr_in* 	sa_in;
			struct in_addr*			in_add;

			sa_in = (struct sockaddr_in *)sa;

			printf( "sa_in->sin_port             : %d\n", ntohs( sa_in->sin_port ) );

			in_add = (struct in_addr *)&sa_in->sin_addr;

			if ( inet_ntop( AF_INET, in_add, ip, sizeof( ip ) ) == NULL )
			{
				fprintf( stderr, "inet_ntop() failed - %s", strerror( errno ) );

				return;
			}
			printf( "sa_in->sin_addr.s_addr      : %s\n", ip );

			break;

		case AF_INET6:
			struct sockaddr_in6* 	sa_in6;
			struct in6_addr*		in_add6;

			sa_in6 = (struct sockaddr_in6 *)sa;

			printf( "sa_in6->sin6_port           : %d\n", ntohs( sa_in6->sin6_port ) );

			in_add6 = (struct in6_addr *)&sa_in6->sin6_addr;

			if ( inet_ntop( AF_INET6, in_add6, ip, sizeof( ip ) ) == NULL )
			{
				fprintf( stderr, "inet_ntop() failed - %s", strerror( errno ) );

				return;
			}
			printf( "sa_in6->sin6_addr.s_addr    : %s\n", ip );

			break;
	}
}
