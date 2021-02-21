/**
   Ô´³ÌÐò£º CheckboxTest.java
*/
import java.awt.*;
import java.applet.*;
public class CheckboxTest extends Applet {
    public void init(){
        setLayout(new BorderLayout());
        CheckboxGroup group = new CheckboxGroup();
        Checkbox check1 = new Checkbox("Picture", group, true);
        Checkbox check2 = new Checkbox("Text", group, false);
        Checkbox check3 = new Checkbox(
                               "Picture and Text", group, false);
        Panel np = new Panel();
        np.add(check1);
        np.add(check2);
        np.add(check3);
        add("North", np);
        Panel sp = new Panel();
        Checkbox cb = new Checkbox("Browser");
        sp.add(cb);
        sp.add(new Checkbox("Mail"));
        sp.add(new Checkbox("News"));
        cb.setState(true);
        add("South", sp);
    }
}
