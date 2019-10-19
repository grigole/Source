/*
 * protocol.h
 *
 *  Created on: Oct. 18, 2019
 *      Author: grigole
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#define MAX_MSG		128

struct tcpecho
{
	int		size;
	char	msg[ MAX_MSG ];
};

#endif /* PROTOCOL_H_ */
