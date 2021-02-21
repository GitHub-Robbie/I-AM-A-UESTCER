//yuanhaonan
package pkg2;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class App extends JFrame implements ActionListener {
	// 实现的点击按钮

	JButton jb1, jb2, jb3;

	public App() {
		JFrame frm = new JFrame();
		jb1 = new JButton("set red");
		jb2 = new JButton("set green");
		jb3 = new JButton("set blue");

		JPanel jp = new JPanel();
		jp.add(jb1);
		jp.add(jb2);
		jp.add(jb3);
		this.add(jp);
		this.setVisible(true);
		this.setDefaultCloseOperation(3);
		this.setSize(500, 500);

		// 需要对按钮就行监听
		jb1.addActionListener(this);// 这里需要指的是当前类
		jb2.addActionListener(this);
		jb3.addActionListener(this);

	}

	public void actionPerformed(ActionEvent e) {

		if (e.getSource() == jb1) {
			jb1.setForeground(Color.RED);
			jb2.setForeground(Color.RED);
			jb3.setForeground(Color.RED);
		} else if (e.getSource() == jb2) {
			jb1.setForeground(Color.GREEN);
			jb2.setForeground(Color.GREEN);
			jb3.setForeground(Color.GREEN);
		} else if (e.getSource() == jb3) {
			jb1.setForeground(Color.BLUE);
			jb2.setForeground(Color.BLUE);
			jb3.setForeground(Color.BLUE);
		}
	}

	public static void main(String[] args) {
		new App();
	}
}