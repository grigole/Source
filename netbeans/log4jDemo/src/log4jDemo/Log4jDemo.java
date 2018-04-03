/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package log4jDemo;

import org.apache.log4j.PropertyConfigurator;
import org.apache.log4j.Logger;

/**
 *
 * @author grigole
 */
public class Log4jDemo {

     static Logger logger = Logger.getLogger(Log4jDemo.class );
            
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        PropertyConfigurator.configure( "src/log4jDemo/log4j.properties" );
        
        logger.debug( "main() entered" );
        logger.debug( "main() exited" );
    }
    
}
