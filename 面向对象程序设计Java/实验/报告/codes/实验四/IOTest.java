//yuanhaonan
package pkg2;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class IOTest {
	public static void main(String[] args) throws IOException {
		File ofile=new File("src/Output.txt");
		if (!ofile.isFile()) {
            ofile.createNewFile();
        }
        BufferedWriter writer = new BufferedWriter(new FileWriter("src/Output.txt"));
        Scanner scanner=new Scanner(System.in);
        String input=scanner.nextLine();
        writer.write(input);
        writer.close();
        scanner.close();
	}
}
