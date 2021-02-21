
/**
   CardLayoutTest.java
*/
import java.awt.*;
import java.applet.*;

public class CardLayoutTest extends Applet {
	public void init() {
		CardLayout layout = new CardLayout();
		setLayout(layout);
		add("1", new Button("Card 1"));
		add("2", new Button("Card 2"));
		add("3", new Button("Card 3"));
		add("4", new Button("Card 4"));
		add("5", new Button("Card 5"));
		for (int i = 1; i < 6; i++) {
			if (i == 1)
				layout.first(this);
			else
				layout.next(this);
			validate();
			setVisible(true);
			try {
				Thread.sleep(3000);
			} catch (Exception e) {
			}
		}
	}
}
