//
//import java.awt.*;
//import java.awt.event.*;
//import java.applet.*;
//public class EventTest2 extends Applet {
//    public void init() {
//        add(new MyButton("Left Button"));
//        add(new MyButton("Right Button"));
//    }
//}
//class MyButton extends Button implements ActionListener{
//    public MyButton(String b) {
//        super(b);
//        addActionListener(this);
//    }
//    public void actionPerformed(ActionEvent e) {
//        String arg = e.getActionCommand();
//        if ("Left Button".equals(arg)) {
//            System.out.println("Press Left Button");
//        } else if ("Right Button".equals(arg)) {
//            System.out.println("Press Right Button");
//        }
//    }
//}
