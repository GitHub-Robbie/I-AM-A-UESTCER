class StaticMember {
	static int i = 0;

	static int incr() {
		return i++;
	}
}

public class StaticTest {
	static double pi;
	static double result;

	double b;

	public static void main(String args[]) {
		StaticMember st1 = new StaticMember();
		StaticMember st2 = new StaticMember();

//		System.out.println(++st1.i);
		System.out.println(st1.i++);
		System.out.println(st1.incr());

		System.out.println(st2.i++);
		System.out.println(st2.incr());

		System.out.println(StaticMember.i++);
		System.out.println(StaticMember.incr());

		pi = Math.PI;
		// static方法的返回值必须传递(赋值)给static成员
//		b = Math.pow(8, 2); 
		result = Math.pow(8, 2);
//		System.out.println(b);

		// static方法不能引用非 static 方法
//		int r = a();
	}

	int a() {
		return 10;
	}
}
