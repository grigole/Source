#ifndef _POSTGRESQL_H
#define _POSTGRESQL_H

#include <libpq-fe.h>

class PostgresqlDB {

    PGconn *pDB = NULL;   // database pointer

public:
    int open_db_postgresql( const char* dbName );
    int close_db_postgresql( void );
    int prepare_db_postgresql( void );
    int add_to_postgresql( int nCount );
    int add_to_postgresql_10( int nCount );
};

#endif // _POSTGRESQL_H
