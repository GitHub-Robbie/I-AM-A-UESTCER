/**
   MenuEvent2.java
*/
import java.awt.*;
import java.awt.event.*;
public class MenuEvent2 extends Frame
                    implements ActionListener, ItemListener{
    String strFont = "serify";
    String strMessage = "Select MenuItem";
    boolean italic = false;
    boolean bold = false;
    public MenuEvent2() {
        super("MenuEvent2 Window");
        FileMenu fileMenu = new FileMenu(this);
        OptionMenu opMenu = new OptionMenu(this, this);
        MenuBar mb = new MenuBar();
        mb.add(fileMenu);
        mb.add(opMenu);
        setMenuBar(mb);
        setSize(new Dimension(400, 300));
        setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        String arg = e.getActionCommand();
        if(arg.equals("TimesRoman")) {
            strFont = "TimesRoman";
        } else if(arg.equals("Fancy")) {
            strFont = "Fancy";
        } else if(arg.equals("Courier")) {
            strFont = "Courier";
        } else if(arg.equals("Exit")) {
            setVisible(false);
            dispose();
            System.exit(0);
        } else return;
        strMessage = "Menu Event Test";
        repaint();
    }
    public void itemStateChanged(ItemEvent e) {
        String arg = (String)e.getItem();
        CheckboxMenuItem check =
                         (CheckboxMenuItem)e.getItemSelectable();
        if(arg.equals("Italic")) {
            italic = check.getState();
        } else if(arg.equals("Bold")) {
            bold = check.getState();
        } else return;
        strMessage = "Menu Event Test";
        repaint();
    }
    public void paint(Graphics g) {
        int[] style = {Font.PLAIN, Font.ITALIC, Font.BOLD,
                          Font.ITALIC|Font.BOLD};
        int i=0;
        if(italic) {
            if(bold) i = 3;
            else i = 1;
        } else if(bold) i = 2;
        g.setFont(new Font(strFont, style[i], 30));
        g.drawString(strMessage, 50, 150);
    }
    public static void main(String[] args) {
        new MenuEvent2();
    }
}
class FileMenu extends Menu {
    public FileMenu(ActionListener action) {
        super("File");
        MenuItem ex = new MenuItem("Exit");
        ex.addActionListener(action);
        add(ex);
    }
}
class OptionMenu extends Menu {
    public OptionMenu(ActionListener action, 
                                            ItemListener item){
        super("Option");
        MenuItem mi1, mi2, mi3, mi4, mi5;
        CheckboxMenuItem ck1, ck2;
        Menu subMenu = new Menu("Font");
        mi1 = new MenuItem("TimesRoman");
        mi2 = new MenuItem("Fancy");
        mi3 = new MenuItem("Courier");
        mi1.addActionListener(action);
        mi2.addActionListener(action);
        mi3.addActionListener(action);
        subMenu.add(mi1);
        subMenu.add(mi2);
        subMenu.add(mi3);
        add(subMenu);
        addSeparator();
        ck1 = new CheckboxMenuItem("Italic");
        ck2 = new CheckboxMenuItem("Bold");
        ck1.addItemListener(item);
        ck2.addItemListener(item);
        add(ck1);
        add(ck2);
    }
}
