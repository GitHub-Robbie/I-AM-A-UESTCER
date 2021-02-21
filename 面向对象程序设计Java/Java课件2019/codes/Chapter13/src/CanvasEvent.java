/**
   Ô´³ÌÐò£ºCanvasEvent.java
*/
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class CanvasEvent extends Applet
                              implements ActionListener {
    MyCanvas mc;
    public void init() {
        Button text, point;
        setLayout(new BorderLayout());
        mc = new MyCanvas();
        add("Center", mc);
        Panel sp = new Panel();
        sp.setLayout(new GridLayout(1, 2));
        text = new Button("Text");
        point = new Button("Point");
        text.addActionListener(this);
        point.addActionListener(this);
        sp.add(text);
        sp.add(point);
        add("South", sp);
        validate();
        point.requestFocus();
    }
    public void actionPerformed(ActionEvent e) {
        String arg = e.getActionCommand();
        if(arg.equals("Text")) {
            mc.setEnablePoint(false);
            mc.setEnableText(true);
        } else if(arg.equals("Point")) {
            mc.setEnableText(false);
            mc.setEnablePoint(true);
        }
    }
}
class MyCanvas extends Canvas implements KeyListener, 
                           MouseListener, MouseMotionListener{
    boolean bText = false;
    boolean bPoint = true;
    boolean bOver = false;
    int x, y;
    int yy = 0;
    String str;
    MyCanvas() {
        super();
        addKeyListener(this);
        addMouseListener(this);
        addMouseMotionListener(this);
    }
    public void keyPressed(KeyEvent e) {
        if(bText) {
            str = e.getKeyText(e.getKeyCode());
            getGraphics().drawString(str, x, yy);
            yy += 14;
        }
    }
    public void mouseClicked(MouseEvent e) {
        x = e.getX();
        y = e.getY();
        if(bText) {
            requestFocus();
            yy = y;
        }
        if(bPoint) {
            bOver = !bOver;
        } 
    } 
    public void mouseMoved(MouseEvent e) {
        if(bOver) {
            int nx, ny;
                nx = e.getX();
            ny = e.getY();
            getGraphics().drawLine(nx, ny, x, y);
            x = nx;
            y = ny;
        }
    }
    public void setEnablePoint(boolean b) {
        bPoint = b;
    }
    public void setEnableText(boolean b) {
        bText = b;
    }
    public void keyTyped(KeyEvent e){}
    public void keyReleased(KeyEvent e){}
    public void mousePressed(MouseEvent e){}
    public void mouseReleased(MouseEvent e){}
    public void mouseEntered(MouseEvent e){}
    public void mouseExited(MouseEvent e){}
    public void mouseDragged(MouseEvent e){}
}
