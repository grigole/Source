/**
 * 
 */

package com.gvrsoft.containers;

import java.util.*;

/**
 * @author grigole
 *
 */
public class Containers {
	
	static private void demoLists()
	{
		List<String> arrayList = new ArrayList<String>();
		
		arrayList.add( "Greg" );
		arrayList.add( "V" );
		arrayList.add( "Rigole" );
		
		arrayList.forEach( System.out::println );
		arrayList.sort( null );
		arrayList.forEach( System.out::println );

		System.out.println();
		
		List<Integer> linkedList = new LinkedList<Integer>();
		
		linkedList.add( 31 );
		linkedList.add( 27 );
		linkedList.add( 49 );
		
		linkedList.forEach( System.out::println );
		linkedList.sort( null );
		linkedList.forEach( System.out::println );
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		demoLists();
	}

}
