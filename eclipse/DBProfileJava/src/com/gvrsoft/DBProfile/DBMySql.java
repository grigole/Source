package com.gvrsoft.DBProfile;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;
import java.sql.ResultSet;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class DBMySql {
	
	private static final Logger log4j = LogManager.getLogger(DBMySql.class.getName());

	private String		dbName = null;
	private Connection	dbConn = null;
	

	/**
	 * Create and open a connection to the MySql database specified by the
	 * properties object.
	 *
	 * @param props The java.util.properties object containing the
	 * 				database connection parameters
	 * @return 0 on success. -1 on error
	 */
	int open_db_mysql( Properties props )
	{
		if ( dbConn != null )
		{
			log4j.warn( "Database is already open" );
			
			return -1;
		}
		
		try {
			
			Class.forName("com.mysql.jdbc.Driver");
			
		} catch (ClassNotFoundException e) {
			
			// TODO Auto-generated catch block
			e.printStackTrace();
			
		}

		dbName = props.getProperty( "db.database" );
		
	    log4j.info( "Opening database \"" + dbName + "\"" );

        try {

    		dbConn = DriverManager.getConnection(
    				"jdbc:mysql://localhost/" + props.getProperty( "db.database" ),
    				props.getProperty( "db.user" ),
    				props.getProperty( "db.passwd" ) );

    		log4j.info( "Database opened successfully" );

        }  // the VM will take care of closing the connection
		catch ( SQLException e ) {
			
			// TODO Auto-generated catch block
			e.printStackTrace();
			
		}
	    
        return 0;
	}

	/**
	 * Close the connection to the MySql database
	 *
	 * @return 0 on success. -1 on error
	 */
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

	/**
	 * Prepare the MySql database for the tests.
	 * <p>
	 * Delete the table RAND (this has the side-effect of removing any
	 * data remaining from a previous test).
	 * <p>
	 * Create the RAND table in preparation for the following tests.
	 *
	 * @return 0 on success. -1 on error
	 */
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