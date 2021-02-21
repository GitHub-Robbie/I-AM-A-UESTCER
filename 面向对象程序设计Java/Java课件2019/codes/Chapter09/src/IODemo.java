import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

class IODemo {
	public static void main(String[] args) {
		try {
			// 使用FileInputStream和FileOutputStream进行文件复制
			FileInputStream fis = new FileInputStream(args[0]);
//			FileOutputStream fos = new FileOutputStream(args[1], false);//改写
			FileOutputStream fos = new FileOutputStream(args[1], true);//附加
			int len;
			byte b[] = new byte[1024];
			// 读取文件，存入字节数组b，返回读取到的字符数，存入read
			len = fis.read(b);
			System.out.println(len);
			while (len != -1) {
				fos.write(b, 0, len);
				len = fis.read(b);
			}
			System.out.println(len);
			fis.close();
			fos.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
