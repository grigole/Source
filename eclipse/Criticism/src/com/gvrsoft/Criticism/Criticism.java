package com.gvrsoft.Criticism;

public class Criticism {

	public static void main(String[] args) {

		// Test 1
		
		Duck d1 = new Duck();
		
		System.out.print( "Duck 1 has " + d1.feet + " feet\n" );
		System.out.print( "Duck 1 has " + d1.legs() + " legs\n" );
		
		LameDuck ld1 = new LameDuck();
		
		System.out.print( "LameDuck 1 has " + ld1.feet + " feet\n" );
		System.out.print( "LameDuck 1 has " + ld1.legs() + " legs\n" );
		
		Duck d2 = new LameDuck();
		
		System.out.print( "Duck 2 has " + d2.feet + " feet\n" );
		System.out.print( "Duck 2 has " + d2.legs() + " legs\n" );
	}

}
