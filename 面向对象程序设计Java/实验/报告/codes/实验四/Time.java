//yuanhaonan
package pkg2;

import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Locale;

public class Time {
	public Time() {
		FirstThread first = new FirstThread();
		SecondThread second = new SecondThread();
		ThirdThread third = new ThirdThread();
		Thread thread1 = new Thread(first);
		Thread thread2 = new Thread(second);
		Thread thread3 = new Thread(third);
		thread1.setPriority(Thread.MIN_PRIORITY);
		thread2.setPriority(Thread.MAX_PRIORITY);
		thread3.setPriority(Thread.MIN_PRIORITY);
		thread1.start();
		thread2.start();
		thread3.start();

	}

	public static void main(String[] args) {
		new Time();
	}
}

class FirstThread implements Runnable {
	public void run() {
		try {
			for (int i = 0; i < 100; i++) {
				SimpleDateFormat sdf = new SimpleDateFormat("北京时间yyyy年MM月dd日HH时mm分ss秒");// 格式化输出日期
				Date now = new Date();
				System.out.println(sdf.format(now));
				Thread.sleep(1000);
				Thread.yield();
			}
		} catch (InterruptedException e) {
		}
	}
}

class SecondThread implements Runnable {
	public void run() {
		try {
			for (int i = 0; i < 100; i++) {
				SimpleDateFormat sdf = new SimpleDateFormat("伦敦时间yyyy年MM月dd日HH时mm分ss秒");// 格式化输出日期
				Date now = new Date();
				long time = 60 * 1000;// 60秒
				Date beforeDate = new Date(now.getTime() - time * 480);// 60秒前的时间
				System.out.println(sdf.format(beforeDate));
				Thread.sleep(1000);
				Thread.yield();
			}
		} catch (InterruptedException e) {
		}
	}
}

class ThirdThread implements Runnable {
	public void run() {
		try {
			for (int i = 0; i < 100; i++) {
				SimpleDateFormat sdf = new SimpleDateFormat("纽约时间yyyy年MM月dd日HH时mm分ss秒");// 格式化输出日期
				Date now = new Date();
				long time = 60 * 1000;// 60秒
				Date beforeDate = new Date(now.getTime() - time * 780);// 60秒前的时间
				System.out.println(sdf.format(beforeDate));
				Thread.sleep(1000);
				Thread.yield();
			}
		} catch (InterruptedException e) {
		}
	}
}