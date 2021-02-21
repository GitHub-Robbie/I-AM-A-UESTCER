/**
 * TestAbst.java
*/
abstract class AbstClass {
	abstract void callMe();//abstract method
	
	AbstClass(){
	}
	
	void meToo(){//non-abstract method
		System.out.println("AbstClass meToo()");
	}
}

class ClassD extends AbstClass{
	void callMe(){//必须实现 abstract 方法
		System.out.println("ClassD callMe()");
	}
}
public class TestAbst{
	public static void main(String args[]){
//		AbstClass varE = new AbstClass();//not allowed
		AbstClass varE = new ClassD();// allowed
		varE.callMe();
		varE.meToo();
		

	}
}
