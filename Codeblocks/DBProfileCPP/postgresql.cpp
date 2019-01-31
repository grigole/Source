#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <log4c.h>

#include <libpq-fe.h>

#include "postgresql.h"

extern log4c_category_t* mycat;

int PostgresqlDB::open_db_postgresql( const char* dbName )
{
    char    connStr[256];

    sprintf( connStr, "dbname=%s host=localhost port=5432 user=grigole", dbName );

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Opening database" );

    pDB = PQconnectdb( connStr );
    if ( PQstatus( pDB ) != CONNECTION_OK )
    {
        fprintf(stderr, "Can't open database: %s\n", PQerrorMessage( pDB ) );
        return 3;
    }

    return 0;
}

int PostgresqlDB::close_db_postgresql( void )
{
    if ( pDB == NULL )
    {
        log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "SQLite Database not open - doing nothing\n" );

        return 0;
    }

    PQfinish( pDB );
    pDB = NULL;

    return 0;
}

int PostgresqlDB::prepare_db_postgresql( void )
{
    char         sSql[ 1000 ];
    PGresult    *res;
    int          st;

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "    Dropping table RAND" );

    if ( pDB == NULL )
    {
        log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "SQLite Database not open\n" );

        return 1;
    }

    strcpy( sSql, "drop table if exists RAND;" );

    res = PQexec( pDB, sSql );
    st = PQresultStatus( res );

    if ( st != PGRES_COMMAND_OK )
    {
        fprintf( stderr, "PQexec() for drop table returns %d\n", st );
        fprintf( stderr, "    %s\n", PQerrorMessage( pDB ) );
        fprintf( stderr, "Stopping\n" );

        return st;
   }

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "    Table dropped" );

    strcpy( sSql, "CREATE TABLE RAND ( \
                    ID SERIAL PRIMARY KEY, \
                    DATA integer \
                   );"
          );


    res = PQexec( pDB, sSql );
    st = PQresultStatus( res );

    if ( st != PGRES_COMMAND_OK )
    {
        fprintf( stderr, "PQexec() for create table returns %d\n", st );
        fprintf( stderr, "    %s\n", PQerrorMessage( pDB ) );
        fprintf( stderr, "Stopping\n" );

        return st;
    }

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "    Table created" );

    return 0;
}

int PostgresqlDB::add_to_postgresql( int nCount )
{
    if ( pDB == NULL )
    {
        log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "SQLite Database not open\n" );

        return 1;
    }

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Adding %d random numbers to database", nCount );

    int     nRand;
    int     st;

    int     x;
    for ( x = 0; x < nCount; x++ )
    {
        nRand = random() % nCount;

        char         sSql[ 1000 ];
        PGresult    *res;

        sprintf( sSql, "insert into RAND ( DATA ) VALUES ( %d );", nRand );

        res = PQexec( pDB, sSql );
        st = PQresultStatus( res );

        if ( st != PGRES_COMMAND_OK )
        {
            fprintf( stderr, "PQexec() for insert one row returns %d\n", st );
            fprintf( stderr, "    %s\n", PQerrorMessage( pDB ) );
            fprintf( stderr, "Stopping\n" );

            return st;
        }
    } /* for */

    return 0;
}

int PostgresqlDB::add_to_postgresql_10( int nCount )
{
    if ( pDB == NULL )
    {
        log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "SQLite Database not open\n" );

        return 1;
    }

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Adding %d random numbers to database in batches of 10 rows", nCount );

    int    nRand;

    int          x;
    int          batch_size = nCount / 10;
    int          nBatch = 0;
    char         sSql[ 10000 ];
    PGresult    *res;
    int          st;

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

            res = PQexec( pDB, sSql );
            st = PQresultStatus( res );

            if ( st != PGRES_COMMAND_OK )
            {
                fprintf( stderr, "PQexec() for insert 10 rows returns %d\n", st );
                fprintf( stderr, "    %s\n", PQerrorMessage( pDB ) );
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
