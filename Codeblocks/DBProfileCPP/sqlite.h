#ifndef _SQLITE_H
#define _SQLITE_H

#include <sqlite3.h>

class SQLiteDB {

    sqlite3 *pDB = NULL;   // database pointer

public:
    int open_db_sqlite( const char* dbName );
    int close_db_sqlite( void );
    int prepare_db_sqlite( void );
    int add_to_sqlite( int nCount );
    int add_to_sqlite_10( int nCount );
};

#endif // _SQLITE_H
