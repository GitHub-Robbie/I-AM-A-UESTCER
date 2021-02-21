import java.util.Scanner;

public class AssertionTest {
	public static void main(String args[]) {
		System.out.println("Input a number: ");
		Scanner scan = new Scanner(System.in);
		double number = scan.nextDouble();
//		 assert number > 0;
		assert number > 0 : "negative?";
		System.out.println(number + "'s square root is: " + Math.sqrt(number));
	}
}
