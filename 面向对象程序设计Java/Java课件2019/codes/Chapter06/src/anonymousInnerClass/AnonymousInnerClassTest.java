package anonymousInnerClass;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.Timer;

public class AnonymousInnerClassTest {
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
	public void start(int interval, final boolean beep) {
		
		// 只有这里才有这种写法，ActionListener是接口，不能实例化。
		ActionListener listener = new ActionListener() 
		{//anonymous inner class
			//实现了 ActionListener 中的抽象方法 actionPerformed
			public void actionPerformed(ActionEvent event) {
				Date now = new Date();
				System.out.println("At the tone, the time is " + now);
				if (beep)
					Toolkit.getDefaultToolkit().beep();
			}
//			static int i =0;
		};//notice ";"
		Timer t = new Timer(interval, listener);
		t.start();
	}
}
