
/**
   GridLayoutTest.java
*/
import java.awt.*;
import java.applet.*;

public class GridLayoutTest extends Applet {
	public void init() {
		setLayout(new GridLayout(3, 2));
		add(new Button("First"), 0);
		add(new Button("Second"), 1);
		add(new Button("Three"), 2);
		add(new Button("Four"), 3);
		validate();
		setVisible(true);
		try {
			Thread.sleep(3000);
		} catch (Exception e) {
		}
		;
		add(new Button("Five"), 2);
	}
}
