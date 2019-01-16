#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <log4c.h>

#include <sqlite3.h>

sqlite3 *pDB = NULL;   // global database pointer

extern log4c_category_t* mycat;

int open_db_sqlite( const char* dbName )
{
    int st;

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Opening database" );

    st = sqlite3_open( dbName, &pDB );
    if ( st )
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg( pDB ) );
        return 3;
    }

    return 0;
}

int close_db_sqlite( void )
{
    if ( pDB == NULL )
    {
        log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "SQLite Database not open - doing nothing\n" );

        return 0;
    }

    sqlite3_close( pDB );
    pDB = NULL;

    return 0;
}

int prepare_db_sqlite( void )
{
    int st;

    char sSql[ 1000 ];
    char *err;

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "    Dropping table RAND" );

    if ( pDB == NULL )
    {
        log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "SQLite Database not open\n" );

        return 1;
    }

    strcpy( sSql, "drop table if exists RAND;" );

    st = sqlite3_exec( pDB,
                       sSql,
                       NULL,
                       NULL,
                       &err
                     );

    if ( st != SQLITE_OK )
    {
        fprintf( stderr, "sqlite3_exec() returns %d\n", st );
        fprintf( stderr, "    %s\n", err );
        fprintf( stderr, "Stopping\n" );

        return st;
    }

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "    Table dropped" );

    strcpy( sSql, "CREATE TABLE RAND ( \
                    ID integer primary key autoincrement, \
                    DATA integer \
                   );"
          );

    st = sqlite3_exec( pDB,
                       sSql,
                       NULL,
                       NULL,
                       &err
                     );

    if ( st != SQLITE_OK )
    {
        fprintf( stderr, "sqlite3_exec() returns %d\n", st );
        fprintf( stderr, "    %s\n", err );
        fprintf( stderr, "Stopping\n" );

        return st;
    }

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "    Table created" );

    return 0;
}

int add_to_sqlite( int nCount )
{
    int st;

    if ( pDB == NULL )
    {
        log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "SQLite Database not open\n" );

        return 1;
    }

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Adding %d random numbers to database", nCount );

    int    nRand;

    int     x;
    for ( x = 0; x < nCount; x++ )
    {
        nRand = random() % nCount;

        char sSql[ 1000 ];
        char *err;

        sprintf( sSql, "insert into RAND ( DATA ) VALUES ( %d );", nRand );
        st = sqlite3_exec( pDB,
                           sSql,
                           NULL,
                           NULL,
                           &err
                         );

        if ( st != SQLITE_OK )
        {
            fprintf( stderr, "sqlite3_exec() returns %d\n", st );
            fprintf( stderr, "    %s\n", err );
            fprintf( stderr, "Stopping\n" );

            return st;
        }
    } /* for */

    return 0;
}

int add_to_sqlite_10( int nCount )
{
    int st;

    if ( pDB == NULL )
    {
        log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "SQLite Database not open\n" );

        return 1;
    }

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Adding %d random numbers to database in batches of 10 rows", nCount );

    int    nRand;

    int     x;
    int     batch_size = nCount / 10;
    int     nBatch = 0;
    char    sSql[ 10000 ];
    char   *err;

    batch_size = 10;

    // TODO - handle sizes not evenly divisible

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Batch size is %d", batch_size );

    sprintf( sSql, "insert into RAND (DATA) VALUES " );

    for ( x = 0; x < nCount; x++ )
    {
        char tmp[ 100 ];

        nRand = random() % nCount;

        if ( nBatch == 0 )
            sprintf( tmp, "(%d)", nRand );
        else
            sprintf( tmp, ",(%d)", nRand );
        strcat( sSql, tmp );
        nBatch++;

        if ( nBatch == batch_size )
        {
            strcat( sSql, ";" );

//            printf( "Executing %s\n", sSql );

            st = sqlite3_exec( pDB,
                               sSql,
                               NULL,
                               NULL,
                               &err
                             );

            if ( st != SQLITE_OK )
            {
                fprintf( stderr, "sqlite3_exec() returns %d\n", st );
                fprintf( stderr, "    %s\n", err );
                fprintf( stderr, "Stopping\n" );
                    return st;
            }

            printf( "Added row %d\n", x+1 );

            // Clean up SQL
            //

            nBatch = 0;
            sprintf( sSql, "insert into RAND (DATA) VALUES " );
        } /* write batch */
    } /* for */

    return 0;
}
