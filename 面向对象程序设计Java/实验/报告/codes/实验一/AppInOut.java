//yuanhaonan
import java.awt.*;
import java.awt.event.*;

public class AppInOut {
	public static void main(String args[]) {
		new FrameInOut();
	}
}
class FrameInOut extends Frame implements ActionListener {
	Label prompt;

	FrameInOut() {
		super("Hello World");
		prompt = new Label("Welcome to Java World");
		
		setLayout(new FlowLayout());// 界面上的图形对象的布局策略
		add(prompt);
		
		setSize(300, 200);
		show();
	}
	public void actionPerformed(ActionEvent e) {
	}
}
