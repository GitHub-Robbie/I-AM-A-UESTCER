//yuanhaonan
package pkg;

import java.util.*;

public class Fib {
	public static int fib(int num) {
		if (num == 1 || num == 2)
			return 1;
		else
			return fib(num - 1) + fib(num - 2);
	}

	public static void main(String[] args) {
		System.out.print("How many Fibonacci numbers do you want to print? ");
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		for (int i = 1; i <= num; i++) {
			if ((i - 1) % 6 == 0)
				System.out.println();
			System.out.print(fib(i) + "\t");
		}
		in.close();
	}
}
