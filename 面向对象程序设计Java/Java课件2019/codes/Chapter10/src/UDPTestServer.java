
/**
 * UDPTestServer.java
*/

import java.net.*;

public class UDPTestServer {
	public static void main(String[] args) throws Exception {
		byte[] buffer = new byte[8192];
		DatagramPacket dp = new DatagramPacket(buffer, buffer.length);
		DatagramSocket server = new DatagramSocket(5678);
		server.receive(dp);
		String s = new String(dp.getData(), dp.getOffset(), dp.getLength());
		System.out.println(s);
	}
}
