/**
 * ConstructionMethodTest.java
 */
class ConstructionMethod {
	int a, b, c;

	ConstructionMethod(int x, int y, int z) {
		a = x;
		b = y;
		c = z;
		System.out.println("ConstructionMethod((int x, int y, int z)");
		System.out.println("\n*******************************************************");
	}

	ConstructionMethod(int x, int y) {
		this(x, y, 10); // should be the first statement
		System.out.println("ConstructionMethod((int x, int y)");
		System.out.println("\n*******************************************************");
	}

	ConstructionMethod(int x) {
		this(x, 10); // should be the first statement
		System.out.println("ConstructionMethod(int x)");
		System.out.println("\n*******************************************************");
	}

	ConstructionMethod() {
		this(10); // should be the first statement
		int a = 2;
		System.out.println(this.a + "   ConstructionMethod()");
		System.out.println("\n*******************************************************");
	}
}

class DefaultMethod {
	int x, y, z;

	void setData(int a, int b, int c) {
		x = a;
		y = b;
		z = c;
	}

	DefaultMethod test() {
//		int x = 10;
		System.out.println(this.x); // 全局变量屏蔽
//		DefaultMethod dm = new DefaultMethod();
//		dm = this;
		System.out.println(this);
		return this;
	}
}

public class ConstructionMethodTest {
	public static void main(String args[]) {

//		ConstructionMethod cm4 = new ConstructionMethod(1, 2, 3);
//		ConstructionMethod cm3 = new ConstructionMethod(1, 2);
//		ConstructionMethod cm2 = new ConstructionMethod(1);
//		ConstructionMethod cm1 = new ConstructionMethod();

		DefaultMethod dm = new DefaultMethod();// 使用默认构造器
		dm.test();

	}
}
