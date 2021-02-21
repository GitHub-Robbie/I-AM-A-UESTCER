
import java.awt.*;
import java.awt.event.*;

public class MenuEvent1 extends Frame implements ActionListener {
	String strFont = "serify";
	String strMessage = "Select MenuItem";

	public MenuEvent1() {
		super("MenuEvent1 Window");
		FontMenu fontMenu = new FontMenu(this);
		MenuBar mb = new MenuBar();
		mb.add(fontMenu);
		setMenuBar(mb);
		setSize(new Dimension(400, 300));
		setVisible(true);
	}

	public void actionPerformed(ActionEvent e) {
		String arg = e.getActionCommand();
		if (arg.equals("TimesRoman")) {
			strFont = "TimesRoman";
		} else if (arg.equals("Fancy")) {
			strFont = "Fancy";
		} else if (arg.equals("Courier")) {
			strFont = "Courier";
		} else if (arg.equals("Exit")) {
			setVisible(false);
			dispose();
			System.exit(0);
		} else
			return;
		strMessage = "Menu Event Test";
		repaint();
	}

	public void paint(Graphics g) {
		g.setFont(new Font(strFont, Font.BOLD, 30));
		g.drawString(strMessage, 50, 150);
	}

	public static void main(String[] args) {
		new MenuEvent1();
	}
}

class FontMenu extends Menu {
	public FontMenu(ActionListener action) {
		super("Font");
		MenuItem mi1, mi2, mi3, mi4;
		mi1 = new MenuItem("TimesRoman");
		mi2 = new MenuItem("Fancy");
		mi3 = new MenuItem("Courier");
		mi4 = new MenuItem("Exit");
		mi1.addActionListener(action);
		mi2.addActionListener(action);
		mi3.addActionListener(action);
		mi4.addActionListener(action);
		add(mi1);
		add(mi2);
		add(mi3);
		addSeparator();
		add(mi4);
	}
}
