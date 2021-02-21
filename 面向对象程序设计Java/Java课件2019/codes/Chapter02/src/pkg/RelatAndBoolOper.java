package pkg;

/**
 * RelatAndBoolOper.java
 */
public class RelatAndBoolOper {
	public static void main(String args[]) {
		int a = 25, b = 3;
		boolean d = a < b;
		System.out.println("a < b = " + d);
		int e = 3;
		if (e != 0 && a / e > 5) {
			System.out.println("a / e = " + a / e);
		}
		int f = 0;
		if (f != 0 && a / 0 > 5) {
			System.out.println("a / f = " + a / f);
		} else {
			System.out.println("f = " + f);
		}
		
		
		
		int n = 0b111; // n = 7
		int p = (n & 0b100) / 0b100;
		System.out.println("p = " + p);
		
		//boolean & operation
		boolean b1=true, b2 = false;
		System.out.println("p = " + (b1 & b2));
		

	}
}
