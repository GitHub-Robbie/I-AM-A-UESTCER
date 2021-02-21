
/**
   GridBagTest.java
*/
import java.awt.*;
import java.applet.*;

public class GridBagTest extends Applet {
	public void init() {
		GridBagLayout gridbag = new GridBagLayout();
		GridBagConstraints c = new GridBagConstraints();
		setLayout(gridbag);
		c.fill = GridBagConstraints.BOTH;
		makebutton("Button1", gridbag, c);
		makebutton("Button2", gridbag, c);
		makebutton("Button3", gridbag, c);
		c.gridwidth = GridBagConstraints.REMAINDER;
		// end row
		makebutton("Button4", gridbag, c);
		makebutton("Button5", gridbag, c); // another row
		c.gridwidth = GridBagConstraints.RELATIVE;
		// next-to-last in row
		makebutton("Button6", gridbag, c);
		c.gridwidth = GridBagConstraints.REMAINDER; // end row
		makebutton("Button7", gridbag, c);
		c.gridwidth = 1; // reset to the default
		c.gridheight = 2;
		makebutton("Button8", gridbag, c);
		c.gridwidth = GridBagConstraints.REMAINDER; // end row
		c.gridheight = 1; // reset to the default
		makebutton("Button9", gridbag, c);
		// c.gridwidth = 1;
		// c.gridheight = 1;
		makebutton("Button10", gridbag, c);
	}

	protected void makebutton(String name, GridBagLayout gridbag, GridBagConstraints c) {
		Button button = new Button(name);
		gridbag.setConstraints(button, c);
		add(button);
	}
}
