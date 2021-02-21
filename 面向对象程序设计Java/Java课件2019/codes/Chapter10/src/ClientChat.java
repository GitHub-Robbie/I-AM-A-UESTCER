
/**
   ClientChat.java
*/
import java.io.*;
import java.net.*;

public class ClientChat {
	public static void main(String[] args) {
		Client client;
		byte[] clientReceive = new byte[256];
		byte[] clientSend = new byte[256];
		boolean quit = false;
		byte ch;
		int i = 0;
		client = new Client("localhost", 8008);
		while (!quit) {
			try {
				System.out.println("\t\tReceive:");
				i = 0;
				while ((ch = (byte) client.in.read()) != '\n') {
					clientReceive[i] = ch;
					i++;
				}
				System.out.println("\t\t" + new String(clientReceive, 0, i));
				System.out.println("Send:");
				i = 0;
				while ((ch = (byte) System.in.read()) != '\n') {
					clientSend[i] = ch;
					i++;
				}
				clientSend[i] = (byte) '\n';
				client.out.println(new String(clientSend, 0, i));
				if ((new String(clientSend, 0, i).indexOf("quit")) != -1)
					quit = true;
			} catch (IOException e) {
				System.out.println("IOEx in client.in.readLine()");
				System.out.println(e);
			}
		}
		try {
			Thread.sleep(2000);
		} catch (Exception e) {
		}
	}
}

class Client {
	public DataInputStream in;
	public PrintWriter out;
	private Socket client;

	public Client(String host, int port) {
		try {
			client = new Socket(host, port);
			out = new PrintWriter(client.getOutputStream(), true);
			in = new DataInputStream(client.getInputStream());
		} catch (IOException e) {
			System.out.println("IOEx: " + e);
		}
	}
}
