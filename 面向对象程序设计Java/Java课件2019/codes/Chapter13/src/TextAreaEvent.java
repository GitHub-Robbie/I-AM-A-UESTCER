///**
//   Դ����TextAreaEvent.java
//*/
//import java.awt.*;
//import java.awt.event.*;
//import java.applet.*;
//public class TextAreaEvent extends Applet
//                    implements ActionListener, TextListener {
//    Label display = new Label("  0  ", Label.CENTER);
//    int count = 0;
//    public void init() {
//        setLayout(new BorderLayout());
//        TextArea ta = new TextArea("Please edit a file");
//        ta.addTextListener(this);$EFX$
//        add("Center", ta);
//        Panel p = new Panel();
//        p.setLayout(new GridLayout(2, 1));
//        display.setFont(new Font("TimesRoman", Font.BOLD, 20));
//        p.add(display);
//        Button button = new Button("Count edit chars");
//        button.addActionListener(this);
//        p.add(button);
//        add("South", p);
//        validate();
//        ta.requestFocus();
//    }
//    public void actionPerformed(ActionEvent e) {
//        display.setText(Integer.toString(count));
//    }
//    public void textValueChanged(TextEvent e) {
//        if(e.getID() == TextEvent.TEXT_VALUE_CHANGED)
//            count ++;
//    }
//}
