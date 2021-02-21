import java.net.*;
import java.io.*;
public class MulticastSender{
	String groupHost="239.2.2.5"; //组播组虚拟IP, D类
	int port=8998; //端口
	public MulticastSender(){
		try{
			byte[] message = "Hello,This is a Client.".getBytes(); //发送信息
      		InetAddress inetAddress = InetAddress.getByName(groupHost); //组播地址
      		DatagramPacket datagramPacket= new  
      				DatagramPacket(message, message.length, inetAddress, port); //发送数据报
//      		DatagramSocket socket = new DatagramSocket(); //DatagramSocket实例
      		MulticastSocket socket = new MulticastSocket(port);
      		socket.setInterface(InetAddress.getLocalHost());
      		socket.joinGroup(inetAddress);
      		socket.send(datagramPacket); //发送数据
      		socket.close(); //关闭端口
    	}
    	catch (Exception exception) {
      		exception.printStackTrace();  //输出错误信息
    	} 
	}
  	public static void main(String[] args){
		new MulticastSender();
	}
}