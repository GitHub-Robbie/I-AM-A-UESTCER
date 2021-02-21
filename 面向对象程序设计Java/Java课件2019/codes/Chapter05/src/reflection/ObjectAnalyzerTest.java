package reflection;

import java.lang.reflect.Field;
import java.util.ArrayList;
import java.lang.reflect.*;

/**
 * This program uses reflection to spy on objects.
 */
public class ObjectAnalyzerTest {
	
	public static void main(String[] args) {
		Student student = new Student("20101120288");
//		student.stuNum = "20101120244";// private variable is invisible
		
		Class cl = student.getClass();
		try {
			Field field = cl.getDeclaredField("stuNum");
			// 这一句对于访问私有域的值是必须的
			field.setAccessible(true);
			// 获得域
			Object object = field.get(student);
//			System.out.println(object);
			
			// 设置域
			field.set(student, "20121120066");
			Object object1 = field.get(student);
			System.out.println(object1);
		} catch (NoSuchFieldException e) {
			e.printStackTrace();
		} catch (SecurityException e) {
			e.printStackTrace();
		} catch (IllegalArgumentException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		}

	}
	
	

}