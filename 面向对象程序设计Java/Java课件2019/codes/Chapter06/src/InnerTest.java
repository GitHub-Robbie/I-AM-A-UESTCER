/**
 * 
 * 内部类 总结：
 * 
 * 1、可以通过外部类的方法调用成员内部类、静态内部类;
 * 
 * 2、内部成员类可以调用内部静态类，但内部静态类不能够调用内部非Static成员类;
 * 
 * 3、内部成员类(非静态)可以调用外部类的静态方法与非静态方法;
 * 
 * 4、静态内部类不能够调用外部类的非静态方法、变量;
 * 
 * 5、外部类的静态方法里可以调用内部成员类,不过调用方法不是"T1 t1=new T1();"，而是：
 * 
 * T1 t1=new InnerTest().new T1();
 * 
 * 6、外部类的静态方法可以直接调用内部静态类
 * 
 * 7、内部静态类与外部类的静态方法与间是畅通无阻，内部成员类与外部类(非静态)所有方法与变量都可以交互（除
 * 
 * 外部静态方法不能够直接调用内部成员类）
 * 
 */

public class InnerTest {
	static int a;

	InnerTest() {
		new T1();// 1. 在外部类的构造函数里，调用内部成员类
		new T2();
	}

	/************* 外部类方法 *************/
	long addLong(long a, long b) {
		return a + b;
	}

	public static int add(int a, int b) {
		return a + b;
	}

	void callT2() {
		new T2();// 1. 通过外部类的方法调用内部类
	}

	/**
	 * 
	 * 内部成员类
	 * 
	 */

	private class T1 {
		T2 t2 = new T2();// 2. 建立一个内部类，内部类调用另一个内部类

		T1() {
			a++;// 2. 内部成员类可以直接调用外部类的静态变量
			// 3. 内部成员类可以调用外部类的静态方法与非静态方法
			System.out.println(addLong(1, 2));
			System.out.println(add(1, 2));
		}
	}

	/**
	 * 
	 * 内部静态类
	 * 
	 */
	static class T2 {

		// 3. 内部静态类不能够直接调用内部成员类
//		 T1 t1 = new T1();
		T2() {
			System.out.println(add(1, 2));
			// 4. 静态内部类不能够调用外部类的非静态方法、变量
//			 addLong(1,2);
			
			InnerTest.a++;// 7. 内部静态类与外部类的静态方法和变量之间是畅通无阻的
		}

	}

	public static void main(String[] args) {

		InnerTest it = new InnerTest();
		it.callT2();
		// 5. 静态方法里面调用内部成员类(非静态)，不过调用方法不是"T1 t1=new T1();"，而是如下：
		T1 t1 = new InnerTest().new T1();
		// 6. 静态方法里面调用内部静态类
		T2 t2 = new T2();
	}

}