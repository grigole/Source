/*
 * config.h
 *
 *  Created on: Oct. 10, 2019
 *      Author: grigole
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <stdio.h>

class tcpConfig
{
private:
	// Fake it for now
	const char* host = "localhost";
	const char* port = "6543";

public:
	tcpConfig( const char* file );

	const char* get_host( void );

	const char* get_service( void );
};

#endif /* CONFIG_H_ */
