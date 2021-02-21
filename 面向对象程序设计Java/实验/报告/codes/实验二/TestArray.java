//yuanhaonan
package pkg;

import java.util.*;

public class TestArray {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		System.out.print("How many elements in the array? ");
		int n = in.nextInt();
		System.out.print("The biggest element in the array? ");
		int max = in.nextInt();
		int[] array = new int[n];

		for (int i = 0; i < array.length; i++) {
			int e = (int) (Math.random() * max);
			array[i] = e;
		}

		System.out.println("Before sorting: " + Arrays.toString(array));
		Arrays.sort(array);

		in.close();
		System.out.println("After sorting: " + Arrays.toString(array));
	}
}
