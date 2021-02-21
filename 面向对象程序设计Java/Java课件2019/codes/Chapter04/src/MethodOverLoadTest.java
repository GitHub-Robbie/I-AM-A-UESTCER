/**
 * MethodOverLoadTest.java
*/
class MethodOverLoad {
	void receive(int i)  {
		System.out.println("Receive 1 int data");
		System.out.println("i = " + i);
	}
	void receive(int x, int y) {
		System.out.println("Receive 2 int datas");
		System.out.println("x = " + x + "    y = " + y);
	}
	void receive(double d) {
		System.out.println("Receive 1 double data");
		System.out.println("d = " + d);
	}
	void receive(String s) {
		System.out.println("Receive 1 string");
		System.out.println("s = " + s);
	}
	
	void receive(String s, int a) {
		System.out.println("Receive 1 string and 1 int");
		System.out.println("s = " + s + ", a = " + a);
	}
	
	void receive(int a, String s) {
		System.out.println("Receive 1 int and 1 string");
		System.out.println("a = " + a + ", s = " + s );
	}
	
//	int receive(int a, String s) {
//		System.out.println("Receive 1 int and 1 string");
//		System.out.println("a = " + a + ", s = " + s );
//		return a;
//	}
	
}
public class MethodOverLoadTest {
	public static void main(String args[])  {
		MethodOverLoad mo = new MethodOverLoad ();
		mo.receive(1);
		mo.receive(2, 3);
		mo.receive(3.14159);
		mo.receive("Very interesting, isn't it?");
		mo.receive("Who", 7);
		mo.receive(7, "Who");
	}
}
