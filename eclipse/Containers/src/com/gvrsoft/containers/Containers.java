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
	
	static final private int ITERS = 100000;

	static private void demoLists()
	{
		System.out.println( "DemoLists() - start\n" );

		List<String> arrayList = new ArrayList<>();
		
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

		System.out.println( "\nDemoLists() - end\n" );
	}
	
	static private void benchmarkArrayList()
	{
		System.out.println( "BenchmarkArrayList() - start\n" );

		List<Integer>	arrayList = new ArrayList<>();
		int				x;
		long			begin, end, diff;
		
		begin = System.currentTimeMillis();

		for ( x= 0; x < ITERS; x++)
		{
			arrayList.add( x );
		}
		
		end = System.currentTimeMillis();
		
		diff = end - begin;
		
		System.out.println( "Load took " + diff + " ms\n" );

		begin = System.currentTimeMillis();
		
		Collections.shuffle( arrayList );

		end = System.currentTimeMillis();
		diff = end - begin;
		
		System.out.println( "Shuffle took " + diff + " ms\n" );

		System.out.println( "BenchmarkArrayList() - end\n\n" );

	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		demoLists();
		benchmarkArrayList();
	}

}
