/**
   Ô´³ÌÐò£º ChoiceTest.java
*/
import java.awt.*;
import java.applet.*;
public class ChoiceTest extends Applet {
    public void init(){
        Choice ch = new Choice();
        ch.addItem("Chocolate");
        ch.addItem("Vanilla");
        ch.addItem("Strawberry");
        ch.addItem("Apple");
        add(ch);
    }
}
