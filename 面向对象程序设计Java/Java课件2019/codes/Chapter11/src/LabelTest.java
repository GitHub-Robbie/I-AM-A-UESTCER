/**
   LabelTest.java
*/
import java.awt.*;
import java.applet.*;
public class LabelTest extends Applet {
    public void init() {
        setLayout(new GridLayout(3, 1));
        Label lable1 = new Label("Label1");
        Label lable2 = new Label("Label2", Label.CENTER);
        Label lable3 = new Label("Label3", Label.RIGHT);
        add(lable1);
        add(lable2);
        add(lable3);
        validate();
        setVisible(true);
        try {Thread.sleep(2000);} catch (Exception e) {};
        String str = lable2.getText();
        lable2.setText(str.toUpperCase());
        int align = lable1.getAlignment();
        lable2.setAlignment(align);
    }
}
