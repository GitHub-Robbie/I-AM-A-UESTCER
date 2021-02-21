class ThreadTest extends Thread {
	private int ticket = 100;

	public void run() {
		while (true) {
			if (ticket > 0) {
				System.out.println(Thread.currentThread().getName() 
						+ " is saling ticket" + ticket--);
			} else {
				break;
			}
		}
	}
}

class RunnableTest implements Runnable {
	private int ticket = 100;

	public void run() {
		while (true) {
			if (ticket > 0) {
				System.out.println(Thread.currentThread().getName() 
						+ " is saling ticket" + ticket--);
			} else {
				break;
			}
		}
	}
}

public class ThreadCompare {
	public static void main(String[] args) {
		/* 一个线程对象只能启动一个线程， 
		 * 无论调用多少遍start()方法，
		 * 结果只有一个线程。
		 */

//		 ThreadTest t = new ThreadTest();
//		 t.start();
//		 t.start();
		
//		 RunnableTest r = new RunnableTest();
//		 Thread t = new Thread(r);
//		 t.start();

		/*
		 * 四个线程各自卖各自的100张票，而不去卖共同的100张票。 
		 * 创建了四个ThreadTest对象，就等于创建了四个资源， 
		 * 每个资源都有100张票，每个线程都在独自处理各自的资源。
		 */
//		 new ThreadTest().start();
//		 new ThreadTest().start();
//		 new ThreadTest().start();
//		 new ThreadTest().start();

		/* 用 Thread 产生了4个线程，处理 RunnableTest 对象
		 * 的共同资源 -- 100 张票
		 */
//		RunnableTest t = new RunnableTest();
//		Thread t1 = new Thread(t);
//		Thread t2 = new Thread(t);
//		Thread t3 = new Thread(t);
//		Thread t4 = new Thread(t);
//		t1.start();
//		t2.start();
//		t3.start();
//		t4.start();
		
		
		/*
		 * setPriority 优先级只有在长期稳定运行的系统中才有用
		 */
		RunnableTest t = new RunnableTest();
		Thread t1 = new Thread(t);
		Thread t2 = new Thread(t);
		Thread t3 = new Thread(t);
		Thread t4 = new Thread(t);
		t1.setPriority(2);
		t2.setPriority(10);
		t3.setPriority(5);
		t4.setPriority(1);
		
		t1.start();
		t2.start();
		t3.start();
		t4.start();
	}
}