import java.util.Scanner;

/**
 * CompareTwoDat.java
 */
public class CompareTwoDat {
	public static void main(String args[]) {
		double douDat1 = 4.18;
		double douDat2 = 9.8;
		if (douDat1 <= douDat2)
			System.out.println(douDat1 + " < = " + douDat2 + "\n");
		else
			System.out.println(douDat2 + " < = " + douDat1 + "\n");

		Scanner in = new Scanner(System.in);
//		int i = in.nextInt();
		double i = in.nextDouble();
		System.out.println("Input is: " + i);

		in.close();
	}
}
