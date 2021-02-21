//: FinalData.java
// The effect of final on fields
class Value {
	int i = 1;
}

public class FinalData {
	// Can be compile-time constants
	final int I1 = 9;
	static final int I2 = 99;
	// Typical public constant:
	public static final int I3 = 39;
	// Cannot be compile-time constants:
	final int I4 = (int) (Math.random() * 20);
	static final int I5 = (int) (Math.random() * 20);
	
	Value v1 = new Value();
	final Value v2 = new Value();
	static final Value v3 = new Value();
	
//	final Value v4; // no initializer
	
	// Arrays:
	final int[] a = { 1, 2, 3, 4, 5, 6 };
//	int[] b = { 1, 2, 3, 4, 5, 6 };
//	a = b;

	public void print(String id) {
		System.out.println(id + ": " + "I4 = " 
				+ I4 + ", I5 = " + I5);
	}

	public static void main(String[] args) {
		FinalData fd1 = new FinalData();
//		fd1.I1++; // Error: can't change final value

//		fd1.v2 = new Value();//
		fd1.v2.i++; // Object isn't a constant!
		fd1.v1 = new Value(); // OK -- not final

		for (int i = 0; i < fd1.a.length; i++){
//			fd1.a = new int[3];//not allowed
			fd1.a[i]++; // Array object is final, but its value a[0], a[1]... is not.
			System.out.println(fd1.a[i]);
		}
//		fd1.v2 = new Value(); // Error: Can't assign reference to a final object
//		fd1.v3 = new Value(); 
		fd1.print("fd1");
		
		System.out.println("Creating a new FinalData");
		
		FinalData fd2 = new FinalData();
		fd2.print("fd2");
		//I4 is not static(may change), 
		//I5 is static (would not change)
	}
} /// :~