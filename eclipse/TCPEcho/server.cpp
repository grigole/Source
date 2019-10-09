/*
 * server.cpp
 *
 *  Created on: Oct. 8, 2019
 *      Author: grigole
 */

#include <stdio.h>
#include <stdlib.h>
#include <log4c.h>

log4c_category_t* mycat = NULL;

int main( int argc, char **argv )
{
	log4c_init();
	mycat = log4c_category_get( "tcp_server.log" );

	log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "argc = %d", argc );

	log4c_fini();
	return 0;
}



