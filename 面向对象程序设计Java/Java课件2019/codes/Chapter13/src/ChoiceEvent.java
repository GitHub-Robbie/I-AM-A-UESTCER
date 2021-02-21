/**
   Ô´³ÌÐò£ºChoiceEvent.java
*/
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class ChoiceEvent extends Applet
                              implements ItemListener {
    Label Display = new Label("Hello World", Label.CENTER);
    public void init() {
        String[] strFont = {"Fancy", "TimesRoman", "Courier", 
                                "Sanserif", "Serif", "Monospaced"};
        setLayout(new BorderLayout());
        Choice fontChoice = new Choice();
        for(int i=0; i<6; i++) {
            fontChoice.addItem(strFont[i]);
        }
        fontChoice.select(strFont[0]);
        fontChoice.addItemListener(this);
        add("East", fontChoice);
        validate();
        fontChoice.requestFocus();
        Display.setFont(new Font(strFont[0], Font.ITALIC, 40));
        add("Center", Display);
    }
    public void itemStateChanged(ItemEvent e) {
        Display.setFont(new Font((String)e.getItem(), 
                                      Font.ITALIC, 40));
        Display.setText("Hello World");
    }
}
