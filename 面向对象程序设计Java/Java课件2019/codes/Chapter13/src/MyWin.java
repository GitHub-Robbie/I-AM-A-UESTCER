/**
   Դ���� MyWin.java
*/
import java.awt.*;
import java.awt.event.*;//�¼���
import javax.swing.*;
public class MyWin extends JFrame{
	public MyWin(String title){
		super(title);
		addWindowListener(new MywinEvent(this));
		//ע�ᴰ�ڼ�������
		/** 
		   new MywinEvent()�Ǽ̳���WindowAdapter������
		   WindowAdapterʵ����WindowListener�ӿ�
		*/
	}
	JButton jbt;
	Color cl=Color.RED;
	void setMyMenu(){
		JMenuBar jmb=new JMenuBar();
		JMenu jmn=new JMenu("�ļ�");
		JMenuItem jmi=new JMenuItem("�˳�");
		jmn.add(jmi);
		jmb.add(jmn);
		setJMenuBar(jmb);
		jmi.addActionListener(new MyactionEvent(this));
		//ע�ᶯ���¼�
	}
	void setMybutton(){
		Container ct=super.getContentPane();
		jbt=new JButton("����");
		jbt.setBackground(cl);
		ct.add(jbt,BorderLayout.CENTER);
		jbt.addMouseListener(new MymouseEvent(this));
		//ע������¼�
	}
	public static void main(String args[]){
		MyWin mw=new MyWin("�¼�--��ʾ");
		mw.setMyMenu();
		mw.setMybutton();
		mw.pack();
		mw.setVisible(true);
	}
}
//���崰�ڼ�������
//Program MywinEvent.java
class MywinEvent extends WindowAdapter{
	MyWin mywin;
	public MywinEvent(MyWin mywin){
		this.mywin=mywin;
	}
	public void windowClosing(WindowEvent we){
		System.exit(0);
	}
}
//���嶯����������
//Program MyactionEvent.java
class MyactionEvent implements ActionListener{
	MyWin mywin;
	public MyactionEvent(MyWin mywin){
		this.mywin=mywin;
	}
	public void actionPerformed(ActionEvent ae){
		System.exit(0);
	}
}
//��������������
//MymouseEvent.java
class MymouseEvent implements MouseListener{
	MyWin mywin;
	public MymouseEvent(MyWin mywin){
		this.mywin=mywin;
	}
	public void mouseClicked(MouseEvent me){
		if(me.getSource()==mywin.jbt)
		if(mywin.jbt.getBackground()!=Color.BLUE){
			mywin.jbt.setBackground(Color.BLUE);
			mywin.repaint();
		}else{
			mywin.jbt.setBackground(Color.RED);
			mywin.repaint();
		}
	}
	public void mouseEntered(MouseEvent me){}
	public void mouseExited(MouseEvent me){}
	public void mousePressed(MouseEvent me){}
	public void mouseReleased(MouseEvent me){}
}
