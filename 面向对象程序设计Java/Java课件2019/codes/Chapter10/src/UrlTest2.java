/**
   UrlTest2.java
*/
import java.net.*;
import java.io.*;
public class UrlTest2 {
   public static void main (String[] args) {
      URL url = null;
      try {
        if(args.length == 0) {
            System.out.println("Use: java UrlTest2 <URL>");
            System.exit(0);
        } else
            url = new URL(args[0]);
        InputStream in = url.openStream();

        if (in != null) {
            for(int c = in.read(); c > 0; c = in.read()) {
                System.out.print((char)c);
            }
        }
      } catch (MalformedURLException e) {
          e.printStackTrace();
      } catch (IOException e) {
          e.printStackTrace();
      }
   }
}
