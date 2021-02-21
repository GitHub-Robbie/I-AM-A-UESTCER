
/**
   TextAreaTest.java
*/
import java.awt.*;
import java.applet.*;

public class TextAreaTest extends Applet {
	public void init() {
		String readStr = "Read Only Area\n" + "_______________________\n\n" + "In this area,\n"
				+ "you can read the text,\n" + "but can not edit it!";
		String editStr = "Edit Area\n" + "_______________________\n\n" + "In this area, \n" + "you can edit any text.\n"
				+ "try it!";
		setLayout(new BorderLayout());
		Panel p = new Panel();
		p.setLayout(new GridLayout(1, 1));
		TextArea readArea = new TextArea(readStr);
		readArea.setEditable(false); // read only
		p.add(readArea);
		TextArea editArea = new TextArea(editStr);
		editArea.setEditable(true);// read and write
		p.add(editArea);
		add("Center", p);
	}
}
