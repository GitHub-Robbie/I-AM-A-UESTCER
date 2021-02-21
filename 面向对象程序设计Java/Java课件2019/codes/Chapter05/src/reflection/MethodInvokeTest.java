package reflection;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class MethodInvokeTest {

	public static void main(String args[])
			throws NoSuchMethodException, IllegalAccessException, InvocationTargetException {
		Foo foo = new Foo("这个一个Foo对象！"); //foo.setMsg("");
		Class clazz = foo.getClass();
		Method[] methods = clazz.getDeclaredMethods();

		Method m1 = clazz.getDeclaredMethod("outInfo");

		Method m2 = clazz.getDeclaredMethod("setMsg", String.class);

		Method m3 = clazz.getDeclaredMethod("getMsg");

		m1.setAccessible(true);
		m2.setAccessible(true);
		m3.setAccessible(true);

//		m1.invoke(foo);
		
//		m2.invoke(foo, "！!!");
//
		String msg = (String) m3.invoke(foo);
		System.out.println(msg);

	}
}
