//yuanhaonan
package pkg;

interface Print {
	void print();
}

public class Interface implements Print {
	public void print() {
		System.out.println("Hello!");
	}

	public static void main(String[] args) {
		Interface test = new Interface();
		test.print();
	}
}
