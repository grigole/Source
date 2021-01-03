/*
 * dump.c - dump binary (or any other files for that matter)
 * 			in a format that dump did for QNX 2
 * 		Jan 4 2021 - Greg Rigole
 * 		- initial draft
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

#define	CHARS_PER_LINE	16

int main( int argc, char *argv[] )
{
	int		n = 0;
	int		ch, chars;
	char	str[ CHARS_PER_LINE ];
	FILE	*fp;

	if ( argc != 2 )
	{
		fprintf( stderr, "use: dump <file>\n" );

		return 1;
	}

	fp = fopen( argv[1], "r" );
	if ( fp == NULL )
	{
		fprintf( stderr, "Unable to open file \"%s\": %s\n", argv[1], strerror( errno ) );

		return 2;
	}

	fprintf( stdout, "%04x : ", n );

	while ( (ch = fgetc( fp )) != EOF )
	{
		chars = n % CHARS_PER_LINE;

		if ( isprint( ch ) )
			str[ chars ] = ch;
		else
			str[ chars ] = '.';

		fprintf( stdout, "%02x ", ch );

		n++;
		chars = n % CHARS_PER_LINE;

		if ( chars == 0 )
		{
			str[ CHARS_PER_LINE ] = '\0';

			fprintf( stdout, " : %s\n", str );

			if ( n != 0 && (ch = fgetc( fp )) != EOF ) 
			{
				ungetc( ch, fp );
				fprintf( stdout, "%04x : ", n );
			}
		}
	}

	// Handle line fragment at end of file

	if ( chars != 0 && chars < CHARS_PER_LINE )
	{
		for ( ; chars < CHARS_PER_LINE; chars++ )
		{
			fprintf( stdout, "   " );
			str[ chars ] = ' ';
		}

		str[ chars ] = '\0';
		fprintf( stdout, " : %s\n", str );
	}

	return 0;
}
