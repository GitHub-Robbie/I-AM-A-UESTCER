/**
   UrlTest1.java
*/
import java.net.*;
public class UrlTest1 {
    public static void main (String[] args) {
        URL url = null;
        try {
            if(args.length == 0) {
                System.out.println("Use: java UrlTest1 <URL>");
                System.exit(0); 
            } else
               url = new URL(args[0]);
            System.out.println("Protocol:\t"
                                    + url.getProtocol());
            System.out.println("Host:\t" + url.getHost());
            System.out.println("File:\t" + url.getFile());
            if(url.getPort() == -1)
               System.out.println("Port:\t" 
                      + "Use the default port for the protocol");
            else
              System.out.println("Port:\t" + url.getPort());
              System.out.println("Reference:\t" + url.getRef());
        } catch (MalformedURLException e) {
            e.printStackTrace();
        }
    }
}
