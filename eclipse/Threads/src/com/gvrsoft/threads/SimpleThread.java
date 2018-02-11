package com.gvrsoft.threads;

import com.gvrsoft.threads.MyRunnable;

public class SimpleThread {

	public static void main(String[] args) {
		
		MyRunnable run = new MyRunnable();
		
		Thread thread = new Thread( run, "New Thread" );
		
		thread.start();
		System.out.println(thread.getName());
		
		thread = new Thread( run, "New Thread 2" );
		
		thread.start();
		System.out.println(thread.getName());
		
		thread = new Thread( run, "New Thread 3" );
		
		thread.start();
		System.out.println(thread.getName());
	}
}
