/**
   Ô´³ÌÐò£ºListEvent1.java
*/
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class ListEvent1 extends Applet
                             implements ItemListener {
    String[] itemStr;
    boolean bDisplay = false;
    public void init() {
        setLayout(new BorderLayout());
        List listItem = new List(5, true);
        for(int i=0; i < 10; i++) {
            listItem.addItem("Item" + i);
        }
        listItem.addItemListener(this);
        add("East", listItem);
        validate();
        listItem.requestFocus();
    }
    public void itemStateChanged(ItemEvent e) {
        List lt = (List)e.getItemSelectable();
        itemStr = lt.getSelectedItems();
        bDisplay = true;
        repaint();
    }
    public void paint(Graphics g) {
        if(bDisplay) {
            g.setFont(new Font("TimesRoman", Font.PLAIN, 24));
            for(int i=0; i<itemStr.length; i++) {
                g.drawString("Selected " +itemStr[i],
                                 50, 50+i*20);
            }
        }
    }
}
