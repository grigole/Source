package com.gvrsoft.tcpecho;

import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class TcpEcho {

	public static void main(String[] args) {

		Socket 			clientSocket;
		OutputStream	out;
		InputStream 	in;
		// Quick hack!
		// TODO - figure out how to do this neatly.
		byte[]			bytes = { 6, 0, 0, 0, 'H', 'e', 'l', 'l', 'o', 0 };
		byte[]			reply = new byte[512];

		try
		{
			clientSocket = new Socket( "localhost", 6543 );
			out = clientSocket.getOutputStream();
			in = clientSocket.getInputStream();
			
			out.write( bytes );
			in.read( reply );
		}
		catch ( Exception e )
		{

			System.out.print( e );
			
		}
	}

}
