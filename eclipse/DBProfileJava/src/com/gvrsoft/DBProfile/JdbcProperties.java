/**
 * 
 */
package com.gvrsoft.DBProfile;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * @author 		grigole
 * @version 	0.1
 * @since		0.1
 *
 */
public class JdbcProperties {

	private static final Logger log4j = LogManager.getLogger(DBMySql.class.getName());

	/**
	 * Retrieve the JDBC connection data from the mysql.properties file.
	 * <p>
	 * Use a java.util.Properties object to read the data from the properties
	 * file.
	 *
	 * @return The Properties object containing the connection data
	 */
	static Properties getConnectionData() {

        Properties props = new Properties();

        String fileName = "mysql.properties";

        try ( FileInputStream propSt = new FileInputStream( fileName ) ) {

        	props.load( propSt );

        } catch (IOException ex) {

        	log4j.error( ex.getMessage(), ex );

        }

        return props;
    }
}