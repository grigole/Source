#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <log4c.h>

#include "sqlite.h"
#include "postgresql.h"
#include "timer.h"

/* definition to expand macro then apply to pragma message */
#define VALUE_TO_STRING(x) #x
#define VALUE(x) VALUE_TO_STRING(x)
#define VAR_NAME_VALUE(var) #var "="  VALUE(var)

log4c_category_t* mycat = NULL;

int main( int argc, char** argv )
{
    int st;

    log4c_init();
    mycat = log4c_category_get( "DBProfile.log" );

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "argc = %d", argc );

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

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "nCount = %d", nCount );

#if 0
    SQLiteDB    db;

    st = db.open_db_sqlite( "./test.db" );
    if ( st )
    {
        db.close_db_sqlite();

        exit( st );
    }

    // Create or truncate RAND table in preparation for test
    //
    st = db.prepare_db_sqlite();
    if ( st )
    {
        db.close_db_sqlite();

        exit( st );
    }

    // Test 1 - Add data to database one row at a time/
    //

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Adding data one row at a time..." );

//    st = add_to_sqlite( nCount );

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Adding data in 10 batches rows at a time..." );

    procTimer_t*     pTime;

    start_timer();

    st = db.add_to_sqlite_10( nCount );
    if ( st )
    {
        db.close_db_sqlite();

        exit( st );
    }

    pTime = stop_timer();

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "user    time : %lf", pTime->user );
    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "sys     time : %lf", pTime->system );
    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "elapsed time : %lf", pTime->time );

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Returning %d", st );

    // Close the database
    //

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Closing database\n" );

    db.close_db_sqlite();
#endif

    PostgresqlDB    db;

    st = db.open_db_postgresql( "grigole" );
    if ( st )
    {
        db.close_db_postgresql();

        exit( st );
    }

    // Create or truncate RAND table in preparation for test
    //
    st = db.prepare_db_postgresql();
    if ( st )
    {
        db.close_db_postgresql();

        exit( st );
    }

    // Test 1 - Add data to database one row at a time/
    //

#if 0
    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Adding data one row at a time..." );

    st = db.add_to_postgresql( nCount );
#endif // 0

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Adding data in 10 batches rows at a time..." );

    procTimer_t*     pTime;

    start_timer();

    st = db.add_to_postgresql_10( nCount );
    if ( st )
    {
        db.close_db_postgresql();

        exit( st );
    }

    pTime = stop_timer();

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "user    time : %lf", pTime->user );
    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "sys     time : %lf", pTime->system );
    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "elapsed time : %lf", pTime->time );

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Returning %d", st );

    // Close the database
    //

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "Closing database\n" );

    db.close_db_postgresql();

    if ( log4c_fini() )
    {
        printf("log4c_fini() failed");
    }

    fprintf( stdout, "st = %d\n", st );
    return st;
}
