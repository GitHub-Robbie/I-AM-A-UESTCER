/**
   EventTest1.java
*/
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class EventTest1 extends Applet {
    public void init() {
        add(new MyButton("Left Button"));
        add(new MyButton("Right Button"));
    }
}
class MyButton extends Button {
    public MyButton(String b) {
        super(b);
        enableEvents(AWTEvent.ACTION_EVENT_MASK);
    }
    public void processEvent(AWTEvent e) {
        ActionEvent ae;
        String arg;
        if(e instanceof ActionEvent) {
            ae = (ActionEvent) e;
            arg = ae.getActionCommand();
            if ("Left Button".equals(arg)) {
                System.out.println("Press Left Button");
                return;
            } else if ("Right Button".equals(arg)) {
                System.out.println("Press Right Button");
                return;
            }
        }
        super.processEvent(e);
    }
}
