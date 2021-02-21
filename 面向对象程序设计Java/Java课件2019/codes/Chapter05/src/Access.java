/* In a class hierarchy, private members remain
private to their class.
This program contains an error and will not
compile.
*/
// Create a superclass.
class SupA {
	int i; // by default
	private int j; // private to A
	void setij(int x, int y) {
		i = x;
		j = y;
	}
}
// A's j is not accessible here.
class SubB extends SupA {
	int total;
	void sum() {
		total = i + super.i; 

//		total = i + super.j; // ERROR, j is not accessible here
	}
}
class Access {
	public static void main(String args[]) {
		SubB subOb = new SubB();
		subOb.setij(10, 12);
		subOb.sum();
		System.out.println("Total is " + subOb.total);
	}
}