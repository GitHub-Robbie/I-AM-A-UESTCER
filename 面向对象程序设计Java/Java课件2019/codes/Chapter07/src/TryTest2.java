/**
 * TryTest2.java
 */
public class TryTest2 {
	public TryTest2() {
		for (int i = 0; i < 2; i++) {
			int k;
			try {
				System.out.println("Outer try block; Test Case #" + i);
				try {
					System.out.println("\tInner try block");
					switch (i) {
					case 0:
						int zero = 0;
						k = 8 / zero;
						break;
					case 1:
						int[] c = new int[3];
						k = c[5];
						break;
					}
				} 

				catch (ArithmeticException e) {
					System.out.println("\tInner> " + e);
				} 

				catch (ArrayIndexOutOfBoundsException e) {
					System.out.println("\tInner> " + e);
					throw e;// 还可以再次抛出该异常！！！
				} 
				catch (Exception e) {
					System.out.println("\tInner> " + e);
				} 

				finally {
					System.out.println("\tInner finally block");
				}
			} catch (ArrayIndexOutOfBoundsException e) {
				System.out.println("Outer> " + e);
			} finally {
				System.out.println("Outer finally block");
			}
		}
	}

	public static void main(String[] args) {
		new TryTest2();
	}
}