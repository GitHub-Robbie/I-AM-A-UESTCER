//yuanhaonan
package pkg;

import java.util.*;

public class IsPrime {
	public static boolean isPrimeNorm(int num) {
		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) {
		long startTime = System.currentTimeMillis();
		Scanner in = new Scanner(System.in);
		System.out.print("Please input n: ");
		int n = in.nextInt();
		in.close();
		int[] array = new int[n + 1];
		for (int i = 0; i < n + 1; i++)
			array[i] = 1;
		for (int i = 2; i < n + 1; i++) {
			if (isPrimeNorm(i) == true)
				array[i] = 0;
		}
		int count = 0;
		for (int i = 1; i < n + 1; i++) {
			if (array[i] == 0) {
				System.out.print(i + "\t");
				count++;
			}
			if (array[i] == 0 && count % 8 == 0)
				System.out.println();
		}
		long endTime = System.currentTimeMillis();
		System.out.println("\nTotal runtime: " + (endTime - startTime) + "ms");
	}
}
