
import java.awt.*;
import java.applet.*;
public class ListTest extends Applet {
    public void init() {
        setLayout(new BorderLayout());
        Panel p = new Panel();
        p.setLayout(new GridLayout(2, 2));
        p.add(new Label("Multiple Selection"));
        p.add(new Label("single Selection"));
        List leftList = new List(6, true);
        for(int i=0; i<15; i++) {
            leftList.addItem("leftItem" + i);
        }
        p.add(leftList);
        List rightList = new List();
        for(int i=0; i<10; i++) {
            rightList.addItem("rightItem" + i);
        }
        p.add(rightList);
        add("North", p);
    }
}
