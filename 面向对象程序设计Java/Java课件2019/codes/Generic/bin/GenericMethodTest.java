
public class GenericMethodTest {
	public static void main(String[] args)
			throws InstantiationException, IllegalAccessException, ClassNotFoundException {

		Generic generic = new Generic();

//		Object obj = generic.<Class>getObject(Class.forName("User"));
		//不用写类型参数<Class>,编译器会自动判别
		Object obj = generic.getObject(Class.forName("User"));
		System.out.println(obj instanceof User);
	}
}

class Generic<T> {
	//泛型方法
	public <T> T getObject(Class<T> c) throws InstantiationException, IllegalAccessException {
		T t = c.newInstance();
		return t;
	}
	
	//不是泛型方法，只是使用了 泛型类 Class<T> 的普通方法
	public T getObject2(Class<T> c) throws InstantiationException, IllegalAccessException {
		T t = c.newInstance();
		return t;
	}
}

class User {
	private String uid;
	private String pwd;

	public String getUid() {
		return uid;
	}

	public void setUid(String uid) {
		this.uid = uid;
	}

	public String getPwd() {
		return pwd;
	}

	public void setPwd(String pwd) {
		this.pwd = pwd;
	}

}
