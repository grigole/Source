package com.gvrsoft.DBProfile;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class DBMySql {

	DBMySql()
	{
	}

	DBMySql( String name )
	{
		dbName = name;
	}
	
	private static final Logger log4j = LogManager.getLogger(DBMySql.class.getName());

	private String		dbName = null;
	private Connection	dbConn = null;

	int open_db_mysql()
	{
		if ( dbName == null )
		{
			log4j.error( "Database name is not set" );
			
			return -2;
		}
		
		return open_db_mysql( dbName );
	}
	
	int open_db_mysql( String name )
	{
		if ( dbConn != null )
		{
			log4j.warn( "Database is already open" );
			
			return -1;
		}

		dbName = name;
		
		try {
			
			Class.forName("com.mysql.jdbc.Driver");
			
		} catch (ClassNotFoundException e) {
			
			// TODO Auto-generated catch block
			e.printStackTrace();
			
		}
		
	    log4j.info( "Opening database \"" + dbName + "\"" );

        try {

    		dbConn = DriverManager.getConnection(
    				"jdbc:mysql://localhost/" + dbName,
    				"grigole",
    				"blueyr" );

    		log4j.info( "Database opened successfully" );

        }  // the VM will take care of closing the connection
		catch ( SQLException e ) {
			
			// TODO Auto-generated catch block
			e.printStackTrace();
			
		}
	    
        return 0;
	}

	int close_db_mysql()
	{
		if ( dbConn == null )
		{
			log4j.warn( "Database has not been opened" );
			
			return -1;
		}
		
	    log4j.info( "Closing database \"" + dbName + "\"" );

        try {

        	dbConn.close();
        	dbConn = null;
        	
    		log4j.info( "Database closed successfully" );
		}  // the VM will take care of closing the connection
		catch ( SQLException e ) {
			
			// TODO Auto-generated catch block
			e.printStackTrace();
			
		}
	    
        return 0;
	}

	int prepare_db_mysql()
	{
		// Database should be open
	    if ( dbConn == null )
	    {
	        log4j.error( "MySql database not open\n" );
	
	        return 1;
	    }
	    
	    log4j.info( "Dropping table RAND" );
	    
	    Statement 	st;
	    String 		sSql = "drop table if exists RAND;";

	    try {

	    	st = dbConn.createStatement(); 
        
    	} 
    	catch ( SQLException ex ) {
            
            log4j.error( ex.getMessage() );

            st = null;

        }

	    try {
		    
	    	st.executeUpdate( sSql );

	    	log4j.info( "Table dropped" );
        
    	} 
    	catch ( SQLException ex ) {
            
            log4j.error( ex.getMessage() );

        }

	    sSql = "CREATE TABLE RAND ( " +
	    		"ID SERIAL PRIMARY KEY, " +
                "DATA integer );";

        // Create new, empty table
               
        try {
    	    	
	    		st.executeUpdate( sSql );

	    		log4j.info( "Empty table created" );
        
    	} 
    	catch ( SQLException ex ) {
            
            log4j.error( ex.getMessage() );

        }
	    
        try {
        	
            st.close();
            
        }
        catch ( SQLException ex ) {

            log4j.error( ex.getMessage() );
            
        }
/*	
	
	
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
*/
	    return 0;
	}
}