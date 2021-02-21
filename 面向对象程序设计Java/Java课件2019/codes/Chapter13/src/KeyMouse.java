///**
//   Դ���� KeyMouse.java
//*/
//import java.awt.*;
//import java.awt.event.*;
//import java.applet.*;
//public class KeyMouse extends Applet {
//    public void init() {
//        MyButton b = new MyButton("Button");
//        setLayout(new BorderLayout());
//        add("North",b);
//        validate();
//        b.requestFocus();
//    }
//}
//class MyButton extends Button {
//    MyButton(String b) {
//        super(b);
//        enableEvents(AWTEvent.KEY_EVENT_MASK);
//        enableEvents(AWTEvent.MOUSE_EVENT_MASK);
//        enableEvents(AWTEvent.MOUSE_MOTION_EVENT_MASK);
//    }
//    public void processKeyEvent(KeyEvent e) {
//      if(e.getID() == KeyEvent.KEY_PRESSED) {
//        int code = e.getKeyCode();
//        int m = e.getModifiers();
//        System.out.println("\n----------------------- Key");
//        System.out.println("getKeyChar():\t"+e.getKeyChar());
//        System.out.println("getKeyCode():\t" + code);
//        System.out.println("getKeyText():\t"
//                               + e.getKeyText(code));
//        System.out.println("getModifiers():\t" + m);
//        System.out.println("getKeyModifiersText():\t"
//                                + e.getKeyModifiersText(m));
//      } else super.processKeyEvent(e);
//    }
//    public void processMouseEvent(MouseEvent e) {
//        System.out.println("\n---------------------- Mouse");
//        System.out.println(e.paramString());
//        super.processMouseEvent(e);
//    }
//    public void processMouseMotionEvent(MouseEvent e) {
//        System.out.println("\n------------------ MouseMotion");
//        System.out.println(e.paramString());
//        super.processMouseMotionEvent(e);
//    }
//}
