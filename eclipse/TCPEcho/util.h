/*
 * util.h
 *
 *  Created on: Oct. 10, 2019
 *      Author: grigole
 */

#ifndef UTIL_H_
#define UTIL_H_

extern "C" {

// Show address family
char* xlate_addr_family( int family, char* text );

// Show contents of a struct addrinfo
void print_addrinfo( struct addrinfo* ad_info );

}

#endif /* UTIL_H_ */
