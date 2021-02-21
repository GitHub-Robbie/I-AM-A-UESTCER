/**
   Ô´³ÌÐò£º ScrollbarTest.java
*/
import java.awt.*;
import java.applet.*;
public class ScrollbarTest extends Applet {
    public void init() {
        Scrollbar upDown, leftRight;
        setLayout(new BorderLayout());
        upDown = new Scrollbar(Scrollbar.VERTICAL, 30, 10,
                                    0, 120);
        leftRight = new Scrollbar(Scrollbar.HORIZONTAL, 5, 20,
                                    0, 150);
        add("East",upDown);
        add("South",leftRight);
        System.out.println("upDown Scollbar");
        System.out.println("Value:\t\t" + upDown.getValue());
        System.out.println("Visible:\t"
                                       + upDown.getVisibleAmount());
        System.out.println("Minimum:\t" + upDown.getMinimum());
        System.out.println("Maximum:\t" + upDown.getMaximum());
    }
}
