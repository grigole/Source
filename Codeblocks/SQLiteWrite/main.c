#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <sqlite3.h>

static int callback( void *NotUsed, int argc, char **argv, char **azColName )
 {
    int i;
    for( i = 0; i<argc; i++ )
    {
        printf( "%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL" );
    }
    printf( "\n" );

    return 0;
}

int main( int argc, char** argv )
{
    int st;

    if ( argc != 2 )
    {
        fprintf( stderr, "use: %s <num_to_add>\n", basename( argv[0] ) ) ;

        exit( 1 );
    }

    int nCount = atoi( argv[1] );
    if ( nCount < 0 || nCount > 100000 )
    {
        fprintf( stderr, "num_to_add must be between 1 and 100,000\n" );

        exit( 2 );
    }

    printf( "Adding %d random numbers to database\n", nCount );

    sqlite3 *pDB;
    st = sqlite3_open( "./test.db", &pDB );
    if ( st )
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg( pDB ) );
        sqlite3_close( pDB );
        exit( 3 );
    }

    sqlite3_stmt *pStmt;

    int    nRand;

    int     x;
    for ( x = 0; x < nCount; nCount++ )
    {
        nRand = random() % nCount;
//        printf( "Adding %ld to database\n", nRand );

//        sSQL = "add "
//        st = sqlite3_prepare_v2( pDB, sSQL, -1, &pStmt, NULL );
    }

    sqlite3_close( pDB );

    return 0;
}
