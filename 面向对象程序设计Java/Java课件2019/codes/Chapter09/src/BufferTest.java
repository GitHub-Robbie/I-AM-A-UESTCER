
/**
   BufferTest.java
*/
import java.io.*;
import java.util.*;

class BufferTest {
	public static void main(String args[]) {
		FileInputStream inf = null;
		BufferedInputStream bis = null;
		Date before;
		int i, ms = 0;
		if (args.length == 0) {
			System.out.println("Use: java BufferTest <filename>");
			System.exit(0);
		}
		try {
			//unbuffered
			inf = new FileInputStream(new File(args[0]));
			before = new Date();
			for (i = 0; inf.read() > -1; i++)
				ms = (int) ((new Date()).getTime() - before.getTime());
			System.out.println("Read unbuffered: " + i + " Bytes " + ms + "ms");
			inf.close();
			
			//buffered
			inf = new FileInputStream(new File(args[0]));
			bis = new BufferedInputStream(inf);
			before = new Date();
			for (i = 0; bis.read() > -1; i++)
				ms = (int) ((new Date()).getTime() - before.getTime());
			System.out.println("Read buffered: " + i + " Bytes " + ms + "ms");
			inf.close();
			bis.close();
		} catch (IOException e) {
			System.out.println("Cannot find " + args[0]);
			System.exit(-1);
		}
	}
}
