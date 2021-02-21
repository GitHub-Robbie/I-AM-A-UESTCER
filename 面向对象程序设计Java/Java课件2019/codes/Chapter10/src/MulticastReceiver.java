import java.net.*;
import java.io.*;

public class MulticastReceiver {

	public static void main(String[] arstring) {
		String groupHost = "239.2.2.5"; // 组播组虚拟IP
		InetAddress inetAddress = null;
		int port = 8998; // 端口
		MulticastSocket multicastSocket = null;
		try {
			multicastSocket = new MulticastSocket(port); // MulticastSocket实例
			inetAddress = InetAddress.getByName(groupHost); // 组地址
			multicastSocket.setInterface(InetAddress.getLocalHost());
			multicastSocket.joinGroup(inetAddress); // 加入到组播组中
			while (true) {
				byte[] received = new byte[128]; // 接收数据缓冲
				DatagramPacket dp = new DatagramPacket(received, received.length); // 接收数据的数据报
				multicastSocket.receive(dp); // 接收数据
				System.out.println("Recieve: " + new String(dp.getData(), 0, dp.getLength())); // 输出接收到的数据
			}
		} catch (Exception exception) {
			exception.printStackTrace(); // 输出出错信息
		} finally {
			if (multicastSocket != null) {
				try {
					multicastSocket.leaveGroup(inetAddress); // 7.使用组播套接字的leaveGroup()方法，离开组播组
					multicastSocket.close(); // 关闭组播套接字
				} catch (IOException e) {
				}
			}
		}
	}
}
