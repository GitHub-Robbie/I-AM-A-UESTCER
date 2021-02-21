
/**
   BorderLayoutTest.java
*/
import java.awt.*;
import java.applet.*;

public class BorderLayoutTest extends Applet {
	Button n, s, w, e, c;

	public void init() {
		setLayout(new BorderLayout());
		n = new Button("North");
		s = new Button("South");
		w = new Button("West");
		e = new Button("East");
		c = new Button("Center");
		add("North", n);
		add("South", s);
		add("West", w);
		add("East", e);
		add("Center", c);
		validate();
		setVisible(true);
		
		

		for (int i = 1; i < 6; i++) {
			if (i != 1)
				add("North", n);
			else
				remove(n);
			if (i != 2)
				add("South", s);
			else
				remove(s);
			if (i != 3)
				add("West", w);
			else
				remove(w);
			if (i != 4)
				add("East", e);
			else
				remove(e);
			if (i != 5)
				add("Center", c);
			else
				remove(c);
			validate();
			setVisible(true);
			try {
				Thread.sleep(1000);
			} catch (Exception e) {
			}
		}
	}
}
