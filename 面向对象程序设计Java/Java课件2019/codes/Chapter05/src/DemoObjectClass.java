
class AAA {
	int i = 0;
	void prt(){
		System.out.println("Test");
	}
}

class DemoObjectClass{
	public static void main(String args[]) {
		Object obj = new AAA();
		obj.hashCode();
		AAA a = (AAA) obj;//must cast obj to the original type.
		a.i = 1;
		System.out.println("i: " + a.i);
		
		String b = "AAAaaa";
		
		System.out.println(obj.hashCode());
		System.out.println(a.hashCode());
		System.out.println("Hello "+ obj);
		System.out.println(a.toString());
		System.out.println(b.toString());
	}
}
