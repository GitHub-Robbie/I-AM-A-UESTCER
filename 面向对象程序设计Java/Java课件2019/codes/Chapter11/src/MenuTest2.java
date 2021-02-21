///**
//   MenuTest2.java
//*/
////Program Name: MenuTest2.java
//import java.awt.*;
//import java.awt.event.*;
//public class MenuTest2 extends Frame {
//    public MenuTest2() {
//        super("MenuTest2 Window");
//        FileMenu fileMenu = new FileMenu();
//        HelpMenu helpMenu = new HelpMenu();
//        MenuBar mb = new MenuBar();
//        fileMenu.setFont(new Font("Fancy", Font.PLAIN, 18));
//        helpMenu.setFont(new Font("Fancy", Font.PLAIN, 18));
//        mb.add(fileMenu);
//        mb.add(helpMenu);
//        setMenuBar(mb);
//        enableEvents(AWTEvent.WINDOW_EVENT_MASK);
//        setSize(new Dimension(400, 300));
//        setVisible(true);
//    }
//    public void processWindowEvent(WindowEvent e) {
//        if (e.getID() == WindowEvent.WINDOW_CLOSING) {
//            setVisible(false);
//            dispose();
//            System.exit(0);
//        } else super.processWindowEvent(e);
//    }
//    public static void main(String[] args) {
//        new MenuTest2();
//    }
//}
//class FileMenu extends Menu {
//    public FileMenu() {
//        super("File");
//        add(new MenuItem("New"));
//        add(new MenuItem("Open"));
//        MenuItem save = new MenuItem("Save");
//        add(save);
//        save.setEnabled(false);
//        addSeparator();
//        MenuItem print = new MenuItem("Print");
//        add(print);
//        print.setEnabled(false);
//        add(new MenuItem("Print setup"));
//        addSeparator();
//        add(new MenuItem("Exit"));
//    }
//}
//class HelpMenu extends Menu {
//    public HelpMenu() {
//        super("Help");
//        Menu subMenu = new Menu("Content");
//        subMenu.add(new MenuItem("Document"));
//        subMenu.add(new MenuItem("Source"));
//        subMenu.add(new MenuItem("Class"));
//        add(subMenu);
//        addSeparator();
//        CheckboxMenuItem check = 
//                             new CheckboxMenuItem("Display Time");
//        add(check);
//        check.setState(true);
//        add(new MenuItem("About MenuTest"));
//    }
//}
