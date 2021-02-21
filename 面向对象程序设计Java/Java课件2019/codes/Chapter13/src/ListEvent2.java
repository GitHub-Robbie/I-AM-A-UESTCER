///**
//   Դ����ListEvent2.java
//*/
//import java.awt.*;
//import java.awt.event.*;
//import java.applet.*;
//public class ListEvent2 extends Applet
//                            implements ActionListener {
//    Label Display = new Label("No Item", Label.CENTER);
//    String[] fontSize = {"10", "16", "20", "24", "28",
//                             "32", "40", "48"};
//    int size;
//        public void init() {
//        setLayout(new BorderLayout());
//        List listItem = new List(5, false);
//        for(int i=0; i < fontSize.length; i++) {
//            listItem.addItem(fontSize[i]);
//        }
//        listItem.addActionListener(this);$EFX$
//        add("East", listItem);
//        validate();
//        listItem.requestFocus();
//        Display.setFont(new Font("Courier", Font.BOLD, 20));
//        add("South", Display);
//    }
//    public void actionPerformed(ActionEvent e) {
//        String arg = e.getActionCommand();
//        size = (new Integer(arg)).intValue();
//        Display.setFont(new Font("Courier", Font.BOLD, size));
//        Display.setText("Selected " + size);
//    }
//}
