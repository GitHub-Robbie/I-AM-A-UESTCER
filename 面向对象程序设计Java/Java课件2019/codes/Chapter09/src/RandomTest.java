/**
   RandomTest.java
*/
import java.io.*;
public class RandomTest {
  public static void main(String[] args) {
	  InputStream is;
    RandomAccessFile raf = null;
    if(args.length != 1) {
      System.err.println("Use:java RandomTest <output file>");
      System.exit(-1);
    }
    try {
      raf = new RandomAccessFile(args[0], "rw");
      char a = 'a';
      byte b = 2;
      String c = "abc";
      byte[] b2 = {'a', 'b', 'c'};
      raf.write(b);
      raf.write(b2, 0, b2.length);
      raf.writeBoolean(true);
      raf.writeChar(a);
      raf.writeBytes(c);
      raf.writeChars(c);
      raf.writeUTF(c);
      raf.writeUTF("abc\n");
      System.out.println("Length of file: " + raf.length());
    } catch (IOException e) {
        System.err.println(e);
    } finally {
        try {
            raf.close();
        }catch (Exception e) {
            System.err.println(e);
        }
    }
  }
}
