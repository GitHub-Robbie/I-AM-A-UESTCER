package localInnerClass;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.Timer;

public class LocalInnerClassTest {
	public static void main(String[] args) {
		TalkingClock clock = new TalkingClock();
		clock.start(1000, true);

		// keep program running until user selects "Ok"
		JOptionPane.showMessageDialog(null, "Quit program?");
		System.exit(0);
	}
}

/**
 * A clock that prints the time in regular intervals.
 */
class TalkingClock {
	/**
	 * Starts the clock.
	 * 
	 * @param interval
	 *            the interval between messages (in milliseconds)
	 * @param beep
	 *            true if the clock should beep
	 */
	public void start( int interval,  boolean beep) {
		int a[] = new int[2];//for counting
//		a = new int[5];//如果上面定义了，那么这个就不能再赋值，因为赋值就变成不是 final 了
		int b =0;
		
		// local inner class
		class TimePrinter implements ActionListener {
			public void actionPerformed(ActionEvent event) {
				Date now = new Date();
				System.out.println("At the tone, the time is " + now);
				if (beep)
					Toolkit.getDefaultToolkit().beep();

//				interval = 1001;//not allowed
				System.out.println(interval);// jdk 8之后，局部内部类可以访问非final变量。但是，是final性质。
				System.out.println(a[0]++);//用一个长度为1的数组来计数，每次都加1.
//				System.out.println(b++);//not allowed, b is final.
			}
		}
		ActionListener listener = new TimePrinter();
		Timer t = new Timer(interval, listener);
		t.start();
	}
}
