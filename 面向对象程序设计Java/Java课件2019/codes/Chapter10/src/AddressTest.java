/**
   AddressTest.java
*/
import java.net.*;
class AddressTest {
  public static void main(String[] args) {
    InetAddress someHost;
    try {
      if(args.length == 0) {
         someHost = InetAddress.getLocalHost();
      } else {
         someHost = InetAddress.getByName(args[0]); 
      }
      System.out.println("Use \"getHostName()\":\t"
                              + someHost.getHostName());
      System.out.println("Use \"getHostAddress()\":\t"
                              + someHost.getHostAddress());
      System.out.println("---------------------------------");
      byte [] addr = someHost.getAddress();
      System.out.println("Use \"getAddress()\":\t"
                              + addr[0] + "/ " + addr[1] + "/ "
                              + addr[2] + "/ " + addr[3] + "/ ");
      System.out.println("Converted address:\t"+ (addr[0]&0xff)
                              + "." + (addr[1]&0xff) + "."
                              + (addr[2]&0xff) + "."
                              + (addr[3]&0xff));
      } catch (UnknownHostException e) {
            e.printStackTrace();
      }
   }
}
