/**
   FlowLayoutTest.java
*/
import java.awt.*;
import java.applet.*;
public class FlowLayoutTest extends Applet {
    public void init() {
//    		setLayout(new FlowLayout());
        setLayout(new FlowLayout(FlowLayout.LEFT));
        for(int i=0;i<10;i++) {
            add(new Button("button" + i));
            validate();
            setVisible(true);
            try {Thread.sleep(500);} catch (Exception e) {};
        }
    }
}
