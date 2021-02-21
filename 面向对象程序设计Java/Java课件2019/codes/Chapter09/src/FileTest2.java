
/**
   FileTest2.java
*/
import java.io.*;

class FileTest2 {
	public static void main(String[] args) {
		File dir, subdir;
		if (args.length != 1) {
			System.err.println("Usage: java FileTest2 <newDirPath>");
			System.exit(-1);
		}
		dir = new File(args[0]);
		if (dir.exists())
			System.out.println(dir.getPath() + " already exist!");
		else {
			if (dir.mkdirs()) {
				System.out.println("Created directory:" + dir.getAbsolutePath());
				subdir = new File(dir, "newSub");
				if (subdir.mkdir()) {
					System.out.println("Created subdirectory:" + subdir.getAbsolutePath());
//					subdir.delete();
				} else
					System.out.println("Could not create subdirectory:" + subdir.getAbsolutePath());
//				dir.delete();
			} else
				System.out.println("Could not create directory " + dir.getAbsolutePath());
		}
	}
}
