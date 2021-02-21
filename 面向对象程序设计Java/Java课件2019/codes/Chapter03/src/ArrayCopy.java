import java.util.Arrays;

class ArrayCopy {
	public static void main(String args[]){
		int[] arrayA = {2, 3, 5, 7, 11};
		int[] arrayB = {13, 17, 19, 23, 29, 9};
		arrayA = arrayB;
		System.out.println(Arrays.toString(arrayA));
		
		int[] arrayC = Arrays.copyOf(arrayA, 99);
		
		System.out.println(Arrays.toString(arrayC));
		
//		for (int e : arrayC) {
//			System.out.println(e);
//		}
	}
}
