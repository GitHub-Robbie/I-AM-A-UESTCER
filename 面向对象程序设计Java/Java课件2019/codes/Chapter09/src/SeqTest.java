/**
   SeqTest.java
*/
import java.io.*;
class SeqTest {
    public static void main(String[] args) {
        FileInputStream fis1 = null;
        FileInputStream fis2 = null;
        FileOutputStream fos = null;
        SequenceInputStream  sis =null;
        int ch;
        if(args.length != 3) {
           System.out.println("Use:java SeqTest "
                               + "<file1> <file2> <outfile>");
           System.exit(0);
        }
        try {
           fis1 = new FileInputStream(new File(args[0]));
           fis2 = new FileInputStream(new File(args[1]));
           fos = new FileOutputStream(new File(args[2]));
        } catch (IOException e) {
           System.out.println("Cannot find file!");
           System.exit(-1);
        }
        sis = new SequenceInputStream(fis1, fis2);
        try {
           while((ch = sis.read()) > -1) fos.write(ch);
           fis1.close();
           fis2.close();
           sis.close();
        } catch (IOException e) {
           System.out.println(e);
           System.exit(-1);
        }
    }
}
