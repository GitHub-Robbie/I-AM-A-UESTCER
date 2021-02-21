// Dynamic Method Dispatch
class ClassA {

	void callme() {
		System.out.println("Inside ClassA's callme method");
	}
}
class ClassB extends ClassA {
	// override callme()
	void callme() {
		System.out.println("Inside ClassB's callme method");
	}
}
class ClassC extends ClassB{
	// override callme()
	void callme() {
		System.out.println("Inside ClassC's callme method");
	}
}
class Dispatch {
	public static void main(String args[]) {
		ClassA a = new ClassA(); // object of type A
		ClassB b = new ClassB(); // object of type B
		ClassC c = new ClassC(); // object of type C
		
		ClassA r; // obtain a reference of type A
		r = a; // r refers to an A object
		r.callme(); // calls A's version of callme
		
		r = b; // r refers to a B object
		r.callme(); // calls B's version of callme
		
		r = c; // r refers to a C object
		r.callme(); // calls C's version of callme
	}
}