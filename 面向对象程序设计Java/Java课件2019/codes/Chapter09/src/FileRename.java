/**
   FileRename.java
*/
import java.io.*;
class FileRename {
  public static void main(String[] args) {
    String mge;
    if(args.length != 2) {
     System.err.println("Use:java FileRename <file1> <file2>");
     System.exit(-1);
   }
   File f1 = new File(args[0]);
   File f2 = new File(args[1]);
   if (f1.equals(f2)) {
     System.err.println(" Cannot rename a file to itself");
     System.exit(-1);
   }
   mge=f1.renameTo(f2)?" is renamed to ":" could not be renamed to";
   System.out.println(f1.getPath() + mge + f2.getPath());
 }
}
