/*
 * Copyright (C) 2018 grigole
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

package com.gvrsoft.Radio;

import org.apache.log4j.PropertyConfigurator;
import org.apache.log4j.Logger;

import com.gvrsoft.Radio.Radio;
        
/**
 *
 * @author grigole
 */
public class RadioTest {

    static Logger logger = Logger.getLogger( RadioTest.class );

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        PropertyConfigurator.configure( "src/com/gvrsoft/Radio/log4j.properties" );
    
        logger.info( "Creating first station" );
        Radio radio = new Radio( "Station 1", "radio://test1.gvrsoft.com" );

        logger.info( "Creating second station" );
        Radio station = new Radio( "Station 2", "radio://test2.gvrsoft.com" );
        
        station.GetNumStations();
        radio.GetNumStations();
    }
    
}
