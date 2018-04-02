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

import java.util.LinkedList;

/**
 *
 * @author grigole
 */
public class Radio {
    
    LinkedList<RadioStation> presets;
    
    // Default constructor
    //
    public Radio()
    {
        presets = null;
    }

    public Radio( String name, String url )
    {
        presets = new LinkedList<RadioStation>();
        
        System.out.println( "Creating station " + name + "/" + url );
        presets.add( new RadioStation( name, url ) );
    }
    
    public int GetNumStations()
    {
        System.out.println( "There are " + presets.size() + " stations." );
        
        return presets.size();
    }
}
