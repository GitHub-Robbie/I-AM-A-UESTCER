/**
 * 源程序： ThreadTest2.java
 */
class FirstT implements Runnable {
	public void run() {
		try {
			System.out.println("First thread starts running.");
			for (int i = 0; i < 6; i++) {
				System.out.println("First " + i);
				Thread.sleep(1000);
				Thread.yield();
			}
			System.out.println("First thread finishes running.");
		} catch (InterruptedException e) {
		}
	}
}

class SecondT implements Runnable {
	public void run() {
		try {
			System.out.println("\tSecond thread starts running.");
			for (int i = 0; i < 6; i++) {
				System.out.println("\tSecond " + i);
				Thread.sleep(1000);
			}
			System.out.println("\tSecond thread finished.");
		} catch (InterruptedException e) {
		}
	}
}

public class ThreadTest2 {
	public ThreadTest2() {
		FirstT first = new FirstT();
		SecondT second = new SecondT();
		
		Thread thread1 = new Thread(first);
		Thread thread2 = new Thread(second);

		thread1.setPriority(Thread.MIN_PRIORITY);
		thread2.setPriority(Thread.MAX_PRIORITY);
		
		thread1.start();
		thread2.start();
	}

	public static void main(String[] args) {
		new ThreadTest2();
	}

}
