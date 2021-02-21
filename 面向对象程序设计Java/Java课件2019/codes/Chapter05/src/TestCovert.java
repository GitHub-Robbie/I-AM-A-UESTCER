/**
 * TestCovert.java
*/
class SuperClass {
	int x;
	int y = 200;
	
	void setX(){
		x = 10;
	}
	void setY() {
		y = 20;
	}
	String getMessage(){
		return "super.x = " + x;
	}
}
class SubClass extends SuperClass {
	int x;
	int z = 300;
	
	void setX() {//overide the method in super class
		x = 100;
	}
	void setZ() {
		z = 1000;
	}
	String getMessage(){
		return "super.x = "+super.x+"\tsub.x = "+this.x;
	}
}
public class TestCovert{
	public static void main(String[] args){

		
		// test 1.
//		SubClass sc = new SubClass();
//		sc.setX();
//		System.out.println(sc.getMessage());
		
//		SuperClass sc = new SubClass(); 
////		SuperClass sc = new SuperClass();
////		SubClass subc = new SubClass();
////		sc = subc;
//		//这里是把子类对象转成父类类型,只能调用父类中定义的属性和方法。(向上转型)
//		sc.setX();
//		//如果子类覆盖了父类中的方法，则调用的是子类覆盖后的那个方法。
//		//如果子类没有覆盖父类中的方法，则调用的是超类那个方法。
//		sc.setY();
//		sc.y= 10; //可以访问超类中的成员y; 
////		sc.setZ();//如果超类没有这个方法，报错。
////		sc.z=10; // 不能访问子类自己创建的成员；
//		System.out.println(sc.getMessage());
//		
//		if (sc instanceof Object)
//			System.out.println("sc 是 SubClass 实例。");
//		if (sc instanceof SuperClass)
//			System.out.println("sc 是 SuperClass 实例。");
		
		
		// test 2.
//		SubClass sc = new SubClass(); 
//		SuperClass sc2 = (SuperClass)sc;
//		//子类转父类，等同于 SuperClass sc = new SubClass();
//		sc2.setX();
//		sc2.y=10;
////		sc2.z=10; // 不能访问子类自己创建的成员；
//		
//		System.out.println(sc2.getMessage());
//		
//		if (sc instanceof SubClass)
//			System.out.println("sc 是 SubClass 实例。");
//		if (sc instanceof SuperClass)
//			System.out.println("sc 是 SuperClass 实例。");
		
		
		
		// test 3.
//		SuperClass sc = new SubClass();  //向上转型
//		//这里是把父类强转成子类,这里千万不能写成
////		SuperClass sc = new SuperClass();
//		//这样的话运行时会报错;
//		//只能是上面的那个SuperClass sc = new SubClass();  
//		
//		if (sc instanceof SubClass)
//			System.out.println("sc 是 SubClass 实例。");
//		if (sc instanceof SuperClass)
//			System.out.println("sc 是 SuperClass 实例。");
//////		
//		SubClass sc2 = (SubClass)sc; //(向下转型)
//		sc2.setX(); 
////		//如果子类覆盖了父类中的方法，则调用的是子类覆盖后的那个方法。
////		//如果子类没有覆盖父类中的方法，则调用的是超类那个方法。
//		sc2.setZ();//可以访问子类中的方法;
//		sc2.y = 10;//可以访问超类中的成员y; 
//		sc2.z = 10;//可以访问子类中的成员z;
//		System.out.println(sc2.getMessage());
		
		//test 4.
		SuperClass sup = new SuperClass(); 
		SubClass sub = new SubClass(); 
//		Object o = new Object();
		if (sup instanceof Object)
			System.out.println("sup 是 Object 实例。");
		if (sub instanceof Object)
			System.out.println("sub 是 Object 实例。");
	
		
	}
}
