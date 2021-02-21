
/**
   Find.java
*/
import java.io.*;

public class Find {
	public static void main(String args[]) {
		BufferedReader bRead = null;
		BufferedWriter bWrite = null;
		String buffer;
		boolean outFile = false;
		int i = 0;
		if (args.length < 2) {
			System.out.println("Use:java Find <input> <String>" + " [output]");
			System.exit(0);
		}
		try {
			FileReader fr = new FileReader(new File(args[0]));
			bRead = new BufferedReader(fr);
		} catch (IOException e) {
			System.out.println("Cannot find " + args[0]);
			System.exit(-1);
		}
		if (args.length == 3) {
			try {
				FileWriter fw = new FileWriter(new File(args[2]));
				bWrite = new BufferedWriter(fw);
				outFile = true;
			} catch (IOException e) {
				System.out.println("Cannot find " + args[2]);
				System.exit(-1);
			}
		}
		try {
			buffer = bRead.readLine();
			while (buffer != null) {
				if (buffer.indexOf(args[1]) != -1) { // 查找字符
					if (outFile) {
						bWrite.write(buffer);
						bWrite.newLine();
					}
					System.out.println(buffer);
					i++;
				}
				buffer = bRead.readLine();
			}
		} catch (IOException e) {
			System.err.println(e);
		} finally {
			try {
				bRead.close();
				if (bWrite != null)
					bWrite.close();
			} catch (Exception e) {
				System.err.println(e);
			}
		}
		System.out.println("\n\n\n------------------------");
		System.out.println("Searched completely");
		if (i != 0) {
			System.out.println("Found " + i + " lines have \"" + args[1] + "\"");
		} else
			System.out.println("Can't find \"" + args[1] + "\"in file" + args[0]);
	}
}
