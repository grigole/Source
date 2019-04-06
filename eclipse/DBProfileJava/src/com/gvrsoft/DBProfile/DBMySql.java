package com.gvrsoft.DBProfile;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class DBMySql {

	private static final Logger log4j = LogManager.getLogger(DBMySql.class.getName());

	private Connection dbConn;
	
	int open_db_mysql( String dbName )
	{
		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	    log4j.trace( "Opening database" );
        System.out.println( "Connecting to database..." );

        try {

    		dbConn = DriverManager.getConnection(
    				"jdbc:mysql://localhost/" + "test",
    				"grigole",
    				"blueyr" );

    		System.out.println( "Success!" );
    	    log4j.trace( "Database opened successfully" );
                
            if ( dbConn != null )
            {
            	dbConn.close();
            }
		}  // the VM will take care of closing the connection
		catch ( SQLException e ) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
/*
	    pDB = PQconnectdb( connStr );
	    if ( PQstatus( pDB ) != CONNECTION_OK )
	    {
	        fprintf(stderr, "Can't open database: %s\n", PQerrorMessage( pDB ) );
	        return 3;
	    }
*/
	    return 0;
	}

}