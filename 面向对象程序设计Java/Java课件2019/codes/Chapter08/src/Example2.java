/**
 * 源程序： Example.java
 */
class Example2 implements Runnable{
	static int balance = 1000;
	int deposit = 1000;
	
	public synchronized void run() {
		int temp;
		System.out.println(Thread.currentThread().getName()  + " trying to deposit " + deposit);
		
		temp = balance;
		System.out.println(Thread.currentThread().getName()  + " getting balance... " + balance);
		
		temp += deposit;
		System.out.println(Thread.currentThread().getName()  + " setting balance... " + temp);
		
		balance = temp;
		System.out.println(Thread.currentThread().getName()  + " new balance set to " + balance);
	}


	public static void main(String[] args) {
		Example2 t = new Example2();
		Thread t1 = new Thread(t, "#1");
		Thread t2 = new Thread(t, "#2");
		t1.start();
		t2.start();
		try {
			t1.join();
			t2.join();
		} catch (InterruptedException e) {
		}
		System.out.println("------------------------------");
		System.out.println("Final balance is " + balance);
	}
}

