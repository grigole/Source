/*
 * main.c
 *
 *  Created on: Nov 12, 2020
 *      Author: grigole
 */

#include <stdio.h>

double func( double x, double y )
{
	return x * y;
}

int main( void )
{
	double x = 2.0, y = 3.0;
	double z;

	z = func( x, y );

	printf( "result = %lf\n", z );

	return 0;
}
