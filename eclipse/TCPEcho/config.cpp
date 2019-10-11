/*
 * config.cpp
 *
 *  Created on: Oct. 10, 2019
 *      Author: grigole
 */

#include "config.h"

tcpConfig::tcpConfig( const char* file )
{
	printf( "Reading file \"%s\"\n", file );
	// load_config_from_file ( file );
}

const char* tcpConfig::get_host( void )
{
	return host;
}

const char* tcpConfig::get_service( void )
{
	return port;
}
