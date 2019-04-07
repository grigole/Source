package com.gvrsoft.DBProfile;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class DBProfile {

	private static final Logger log4j = LogManager.getLogger(DBProfile.class.getName());

	public static void main(String[] args) {

		log4j.info( "Creating DBMySql");

		DBMySql database = new DBMySql( "test" );
		
		log4j.info( "Opening database");
		database.open_db_mysql();

		log4j.info( "Closing database");
		database.close_db_mysql();
	}
}