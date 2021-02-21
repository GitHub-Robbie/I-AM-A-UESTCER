// Using super to overcome name hiding.
class FA {
	int i;
}
// Create a subclass by extending class A.
class SB extends FA {
	int i; // this i hides the i in A
	SB(int a, int b) {
		super.i = a; // i in A

		i = b; // i in B
	}
	void show() {
		System.out.println("i in superclass: " + super.i);
		System.out.println("i in subclass: " + i);
	}
	SB getObject(){
		return this;
	}
}
class UseSuper extends FA{
	public static void main(String args[]) {
		SB subOb = new SB(1, 2);
		subOb.show();
		System.out.println("****************************");
		subOb.getObject().show();
		
		//cannot use super in static fields
//		super.i;
		
		//cannot use this in static fields;
//		this.i;
	}
}