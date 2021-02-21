/**
   TextFieldTest.java
*/
import java.awt.*;
import java.applet.*;
public class TextFieldTest extends Applet {
    public void init() {
        setLayout(new BorderLayout());
        Panel p = new Panel();
        p.setLayout(new GridLayout(2, 2));
        p.add(new Label("Enter User Name:  ", Label.RIGHT));
        TextField tf1 = new TextField(30);
        p.add(tf1);
        p.add(new Label("Enter Password:  ", Label.RIGHT));
        TextField tf2 = new TextField(30);
        tf2.setEchoChar('*');
        p.add(tf2);
        add("North", p);
    }
}
