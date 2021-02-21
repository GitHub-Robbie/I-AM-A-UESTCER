package lambda;

//替换匿名内部类
public class LambdaTest1 {
	public static void main(String[] args) {
		// Java 8 之前：
		new Thread(new Runnable() {
			// @Override
			public void run() {
				System.out.println("Before Java8, too much code for too little to do");
			}
		}).start();
		// Java 8 之后：
		new Thread(() -> System.out.println("In Java8, Lambda expression rocks !!")).start();
	}
}
