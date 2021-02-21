/**
   Ô´³ÌÐò£ºScrollbarEvent.java
*/
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class ScrollbarEvent extends Applet 
                                 implements AdjustmentListener {
    Scrollbar eastscroll, southscroll;
    Label horlabel = new Label("Horizontal: 0", Label.CENTER);
    Label verlabel = new Label("Vertical: 0", Label.CENTER);
    public void init() {
        setLayout(new BorderLayout());
        eastscroll = new Scrollbar(Scrollbar.VERTICAL, 0, 10,
                                        0, 100);
        southscroll = new Scrollbar(Scrollbar.HORIZONTAL,
                                          0, 10, 0, 100);
        eastscroll.addAdjustmentListener(this);
        southscroll.addAdjustmentListener(this);
        add("East", eastscroll);
        add("South",southscroll);
        Panel p = new Panel();
        p.setLayout(new GridLayout(2,1));
        verlabel.setFont(new Font("TimesRoman", 
                                        Font.BOLD, 24));
        horlabel.setFont(new Font("TimesRoman", 
                                        Font.BOLD, 24));
        p.add(horlabel);
        p.add(verlabel);
        add("Center", p);
    }
    public void adjustmentValueChanged(AdjustmentEvent e) {
        Scrollbar scroll = (Scrollbar)e.getAdjustable();
        if(scroll == eastscroll) {
            verlabel.setText("Vertiacl: " + scroll.getValue());
        } else if(scroll == southscroll) {
            horlabel.setText("Horizontal: "
                                 + scroll.getValue());
        } else return;
    }
} 
