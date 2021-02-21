//yuanhaonan
package pkg;

import java.util.*;

public class NumAdd {
	public static void main(String[] args) {
		int sum = 0;
		int remainder;
		System.out.print("Please input an integer: ");
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		in.close();
		while (num > 0) {
			remainder = num % 10;
			sum += remainder;
			num /= 10;
		}
		System.out.println("Sum of each digits is: " + sum);
	}
}
