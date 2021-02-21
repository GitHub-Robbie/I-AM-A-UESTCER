
/**
   RandCopy.java
*/
import java.io.*;

class RandCopy {
	public static void main(String args[]) {
		RandomAccessFile raf1 = null, raf2 = null;
		long fileSize = -1;
		byte[] buffer;
		if (args.length != 2) {
			System.out.println("Use:java RandCopy <file1> <file2>");
			System.exit(0);
		}
		if (args[0].equals(args[1])) {
			System.out.println(args[0]);
			System.out.println("File cannot copied onto itself!");
			System.exit(-1);
		}
		try {
			raf1 = new RandomAccessFile(new File(args[0]), "r");
			fileSize = raf1.length();
		} catch (IOException e) {
			System.out.println("Cannot find " + args[0]);
			System.exit(-1);
		}
		try {
			raf2 = new RandomAccessFile(new File(args[1]), "rw");
		} catch (IOException e) {
			System.out.println("Cannot open " + args[1]);
			System.exit(-1);
		}
		buffer = new byte[(int) fileSize];
		try {
			raf1.readFully(buffer, 0, (int) fileSize);
			raf2.write(buffer, 0, (int) fileSize);
		} catch (IOException e) {
			System.out.println("Can't copy file " + args[0] + " to " + args[1]);
		} finally {
			try {
				raf1.close();
				raf2.close();
			} catch (Exception e) {
				System.err.println(e);
			}
		}
	}
}
