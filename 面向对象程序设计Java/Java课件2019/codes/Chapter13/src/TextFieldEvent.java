/**
   Ô´³ÌÐò£ºTextFieldEvent.java
*/
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class TextFieldEvent extends Applet
                                  implements ActionListener {
    String strMessage = "Hello";
    TextField textfield = new TextField("Hello",20);
    public void init() {
        setLayout(new BorderLayout());
        Panel p = new Panel();
        p.setLayout(new GridLayout(1,2));
        p.add(new Label("Please input message: ",Label.RIGHT));
        p.add(textfield);
        textfield.addActionListener(this);
        add("South", p);
        validate();
        textfield.requestFocus();
    }
    public void actionPerformed(ActionEvent e) {
        strMessage = e.getActionCommand();
        repaint();
    }
    public void paint(Graphics g) {
        g.setFont(new Font("TimesRoman", Font.BOLD, 40));
        g.drawString(strMessage, 50, 150);
        textfield.setText("");
    }
}
