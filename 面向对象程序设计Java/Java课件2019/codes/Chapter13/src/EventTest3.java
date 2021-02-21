/**
   EventTest3.java
*/
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class EventTest3 extends Applet
                             implements ActionListener{
    Button left, right;
    public void init() {
        left = new Button("Left Button");
        right = new Button("Right Button");
        left.addActionListener(this);
        right.addActionListener(this);
        add(left);
        add(right);
    }
    public void actionPerformed(ActionEvent e) {
        String arg = e.getActionCommand();
        if ("Left Button".equals(arg)) {
            System.out.println("Press Left Button");
        } else if ("Right Button".equals(arg)) {
            System.out.println("Press Right Button");
        }
    }
}
