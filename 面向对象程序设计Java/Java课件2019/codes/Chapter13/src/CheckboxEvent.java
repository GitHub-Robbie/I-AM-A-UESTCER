/**
   CheckboxEvent.java
*/
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class CheckboxEvent extends Applet
                                implements ItemListener {
    Label Display = new Label("Hello World", Label.CENTER);
    CheckboxGroup cbg;
    Checkbox cbFancy, cbTimes, cbItalic, cbBold;
    boolean bTimes = false;
    boolean bItalic = false;
    boolean bBold = false;
    public void init() {
        cbg = new CheckboxGroup();
        cbFancy = new Checkbox("Fancy Font", cbg, true);
        cbTimes = new Checkbox("TimesRoman Font", cbg, false);
        cbFancy.addItemListener(this);
        cbTimes.addItemListener(this);
        cbItalic = new Checkbox("Italic");
        cbBold = new Checkbox("Bold");
        cbItalic.addItemListener(this);
        cbBold.addItemListener(this);
        setLayout(new BorderLayout());
        Panel p = new Panel();
        p.setLayout(new GridLayout(2, 2));
        p.add(cbFancy);
        p.add(cbTimes);
        p.add(cbItalic);
        p.add(cbBold);
        add("South", p);
        validate();
        cbFancy.requestFocus();
        Display.setFont(new Font("Fancy", Font.PLAIN, 60));
        add("Center", Display);
    }
    public void itemStateChanged(ItemEvent e) {
        String str = (String)e.getItem();
        Checkbox cb =  (Checkbox)e.getItemSelectable();
        if(str.equals("Fancy Font")) {
            bTimes = false;
        } else if(str.equals("TimesRoman Font")) {
            bTimes = true;
        } else if(str.equals("Italic")) {
            bItalic = cb.getState();
        } else if(str.equals("Bold")) {
            bBold = cb.getState();
        }
        DisplayChange();
    }
    public void DisplayChange() {
        String strFont;
        int[] styleValues = {Font.PLAIN, Font.ITALIC,
                                 Font.BOLD, Font.ITALIC|Font.BOLD};
        int i=0;
        if(bTimes) strFont = "TimesRoman";
        else strFont = "Fancy";
        if(bItalic) {
            if(bBold) i = 3;
            else i = 1;
        } else if(bBold) i = 2;
               else i = 0;
        Display.setFont(new Font(strFont,styleValues[i],60));
        Display.setText("Hello World");
    }
}
