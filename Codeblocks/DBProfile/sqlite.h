#ifndef _SQLITE_H

#define _SQLITE_H

extern int open_db_sqlite( const char* dbName );
extern int close_db_sqlite( void );
extern int prepare_db_sqlite( void );
extern int add_to_sqlite( int nCount );
extern int add_to_sqlite_10( int nCount );

#endif // _SQLITE_H
