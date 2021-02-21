package pkg;

/**
 * TestConditionArith.java
 */
class TestConditionArith {
	public static void main(String args[]) {
		int i = 10;
		int j = 10;
		int k = 0;
		boolean test = false;
		System.out.println("k\t" + "i\t" + "j");
		k = test ? (i = 1) : (j = 2);
		System.out.println(k + "\t" + i + "\t" + j);
		test = true;
		k = test ? (i = 20) : (j = 30);
//		k=i=20;
		System.out.println(k + "\t" + i + "\t" + j);
	}
}
