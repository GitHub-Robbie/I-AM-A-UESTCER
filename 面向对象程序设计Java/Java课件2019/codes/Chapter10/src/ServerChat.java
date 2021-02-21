
/**
ServerChat.java
*/
import java.util.*;
import java.io.*;
import java.net.*;

public class ServerChat {
	final static int SERVER_PORT = 8008;

	public static void main(String[] args) {
		Server server;
		byte[] serverReceive = new byte[256];
		byte[] serverSend = new byte[256];
		boolean quit = false;
		byte ch;
		int i = 0;
		server = new Server(SERVER_PORT);
		while (!quit) {
			try {
				System.out.println("\t\tReceive:");
				i = 0;
				while ((ch = (byte) server.in.read()) != '\n') {
					serverReceive[i] = ch;
					i++;
				}
				System.out.println("\t\t" + new String(serverReceive, 0, i));
				if (new String(serverReceive, 0, i).indexOf("quit") == -1) {
					System.out.println("Send:");
					i = 0;
					while ((ch = (byte) System.in.read()) != '\n') {
						serverSend[i] = ch;
						i++;
					}
					serverSend[i] = '\n';
					server.out.println(new String(serverSend, 0, i));
				} else {
					quit = true;
				}
			} catch (IOException e) {
				System.out.println("IOEx in server.in.readLine()" + e);
			}
		}
	}
}

class Server {
	private ServerSocket server;
	private Socket socket;
	public DataInputStream in;
	public PrintWriter out;

	public Server(int port) {
		try {
			server = new ServerSocket(port);
			System.out.println("--- Chat Server is on_line! ---");
			socket = server.accept();
			in = new DataInputStream(socket.getInputStream());
			out = new PrintWriter(socket.getOutputStream(), true);
			out.println("Chat Server:  " + new Date());
		} catch (IOException e) {
			System.out.println("Serverconstructor IOEx: " + e);
		}
	}
}
