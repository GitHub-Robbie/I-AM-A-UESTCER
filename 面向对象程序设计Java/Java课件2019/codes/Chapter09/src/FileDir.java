/**
   FileDir.java
*/
import java.io.File;
import java.util.Date;
class FileDir {
   public static void main(String[] args) {
     if (args.length != 1) {
       System.err.println("Usage: java FileDir <filepath>");
       System.exit(-1);
     }
     File f = new File(args[0]);
     String[] ls = f.list();
     for (int i = 0; ls != null && i < ls.length; i++)
       printOne(new File(f, ls[i]));
  }
  public static void printOne(File f) {
    if (f.exists()) {
      System.out.print(f.canRead() ? "r" : "-");
      System.out.print(f.canWrite() ? "w" : "-");
      System.out.print(f.isDirectory() ? "d" : "-");
      if(!f.isDirectory())
          System.out.print("\t\t" + f.length());
      else
          System.out.print("\t<Dir>\t");
      System.out.print('\t');
      System.out.print(new Date(f.lastModified()));
      System.out.print('\t');
    } else {
       System.out.print("\t\t\t\t\t");
    }
    System.out.println(f.getName());
  }
}
