//yuanhaonan
package pkg2;
 
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
 
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JTextArea;
//让其继承窗口类
public class NotePal extends JFrame implements ActionListener {

	private static final long serialVersionUID = 1L;	//定义一个文本框
	JTextArea jTextArea = null;		//定义一个菜单栏
	JMenuBar jMenuBar = null;	//定义一个菜单
	JMenu jMenu1 = null;	//定义一个“打开”子选项
	JMenuItem jMenuItem1 = null;	//定义一个“保存”子选项
	JMenuItem jMenuItem2 = null;	//定义一个文件选择
	JFileChooser jFileChooser = null;	//定义一个FileReader文件输入流
	FileReader fileReader = null;	//定义一个FileWriter输出流
	FileWriter fileWriter = null;	//定义一个缓冲字符输入流
	BufferedReader bufferedReader = null;	//定义一个缓冲字符输出流
	BufferedWriter bufferedWriter = null;
//	@SuppressWarnings("unused")
	public static void main(String[] args) {
		NotePal notePal = new NotePal();
	}
	
	public NotePal()
	{
		jTextArea = new JTextArea();
		jMenuBar = new JMenuBar();
		jMenu1 = new JMenu("文件");
		jMenuItem1 = new JMenuItem("打开");
		jMenuItem1.addActionListener(this);
		jMenuItem1.setActionCommand("打开");
		jMenuItem2 = new JMenuItem("保存");
		jMenuItem2.addActionListener(this);
		jMenuItem2.setActionCommand("保存");
		jTextArea.setBackground(Color.LIGHT_GRAY);
		
		//将组件添加上各自的位置
		//将jMenuBar添加到JFrame中
		this.setJMenuBar(jMenuBar);
		//将jMenu添加到jMenuBar中
		jMenuBar.add(jMenu1);
		//将jMenuTItem1添加到Jmenu1中
		jMenu1.add(jMenuItem1);
		//将jMenuTItem2添加到Jmenu1中
		jMenu1.add(jMenuItem2);
		//将jTextArea添加到JFrame中
		this.add(jTextArea);
		
		//设置窗体的标题
		this.setTitle("记事本");
		//设置窗体的大小
		this.setSize(600,400);
		//当关闭窗口的时候，关闭进程
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//显示窗口
		this.setVisible(true);
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getActionCommand().equals("打开"))
		{
			//实例化一个JFileChoose
			jFileChooser = new JFileChooser();
			//设置文件选择窗口的名字
			jFileChooser.setDialogTitle("选择文件...");
			//设置文件窗口的默认路径
			jFileChooser.showOpenDialog(null);
			//显示文件窗口
			jFileChooser.setVisible(true);
			//用address保存用户编辑文件的绝对路径
				String address = jFileChooser.getSelectedFile().getAbsolutePath();
			try {
				//为fileReader分配空间
				fileReader = new FileReader(address);
				//为bufferedReader分配空间
				bufferedReader = new BufferedReader(fileReader);
				//定义一个str判断输入的字符是否已经为空
				String str = "";
				//定义一个strAll接收文件的全部信息
				String strAll = "";
				//读取文件信息，并将其保存到strAll中
				while((str = bufferedReader.readLine()) != null)
				{
					strAll += str + "\r\n";
				}
				//将strAll中的全部信息显示到JTextArea上
				jTextArea.setText(strAll);
			} catch (Exception e2) {
				e2.printStackTrace();
			}finally{
				try {
					//关闭文件
					bufferedReader.close();
					fileReader.close();
				} catch (Exception e3) {
					e3.printStackTrace();
				}
			}
		}
		//如果用户点的是保存按钮
		if(e.getActionCommand().equals("保存"))
		{
			//创建一个保存窗口
			JFileChooser jFileChooser1 = new JFileChooser();
			//设置窗口名字
			jFileChooser1.setDialogTitle("另存为...");
			//设置默认设置
			jFileChooser1.showSaveDialog(null);
			//显示窗口
			jFileChooser1.setVisible(true);
			try {
				//为fileWrite分配空间
				fileWriter = new FileWriter(jFileChooser1.getSelectedFile().getAbsolutePath());
				//为bufferedWrite分配空间
				bufferedWriter = new BufferedWriter(fileWriter);
				//保存进去
				bufferedWriter.write(this.jTextArea.getText());
				
			} catch (Exception e2) {
				e2.printStackTrace();
			}finally{
				//关闭文件
				try {
					bufferedWriter.close();
					fileWriter.close();
				} catch (Exception e3) {
					e3.printStackTrace();
				}
			}
		}
	}
}
