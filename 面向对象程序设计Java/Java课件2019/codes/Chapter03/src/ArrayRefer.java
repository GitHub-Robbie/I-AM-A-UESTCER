import java.util.Arrays;


/**
 * ArrayRefer.java
 */
public class ArrayRefer {
	public static void main(String args[]) {
		int[] arrayA = new int[5];
		
		System.out.println("Initial value:");
		
		for (int i = 0; i < arrayA.length; i++) {
			System.out.println("arrayA[" + i + "] = " + arrayA[i]);
		}
		
		
		for (int i = 0; i < arrayA.length; i++) {
			arrayA[i] = i;
		}
		
		
		System.out.println("Refresh value:");
		for (int i = 0; i < arrayA.length; i++) {
			System.out.println("arrayA[" + i + "] = " + arrayA[i]);
		}

		for (int i : arrayA) {
			System.out.println("****arrayA: " + i);
		}

		for (int e : arrayA) {
			System.out.println("****arrayA[" + e + "] = " + arrayA[e]);
		} // why not?
		
		System.out.println("arrayA to string: " + Arrays.toString(arrayA));

		// anonymous array
		int[] arrayB = {2, 3, 5, 7, 11 };
//		 arrayB = {13, 17, 19, 23, 29};//ERROR
		arrayB = new int[] { 13, 17, 19, 23, 29 };
		
		int b[] = new int[0];
		System.out.println("length of b: " + b.length);
//		System.out.println(b[0]);//not allowed... because the length of the array is 0.
	}
}
