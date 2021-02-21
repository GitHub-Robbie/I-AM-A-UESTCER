/**
   ButtonTest.java
*/
import java.awt.*;
import java.applet.*;

public class ButtonTest extends Applet {
    Button b;
    public void init() {
        b=new Button("HELLO WORLD");
        add(b);
        validate();
        setVisible(true);
        try {Thread.sleep(3000);} catch (Exception e) {};
        String label=b.getLabel();
        b.setLabel(label.toLowerCase());
    }
}
