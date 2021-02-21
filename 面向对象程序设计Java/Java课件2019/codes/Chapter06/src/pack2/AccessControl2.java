/**
 * AccessControl2.java
*/
package pack2;
import pack1.Original2;
class Derived extends Original2{
//	int nProtected = 5;
	void access() {
		System.out.println("** 在不同包的子类中,可访问的成员: **");
//		System.out.println("  Private member = " + nPrivate);
//		System.out.println("  Default member = " + nDefault);
		
//		nProtected = 5;
		// OK, 1. 没有覆盖，访问的是超类的protected；2. 覆盖了，访问的是子类覆盖后的
		System.out.println("  Protected member = "+nProtected);
		System.out.println("  Protected member = "+super.nProtected);//OK, 可以通过super访问超类中的protected 成员。
		
		Original2 o2 = new Original2();
//		System.out.println("  Protected member = "+o2.nProtected);//not allowed.
		System.out.println("  Protected static member = "+o2.nProtected_static);//static is allowed.
		
//		System.out.println("  Public  member = "+nPublic);
	}
}
class AnotherPackage{
	void access() {
		Original2 o = new Original2();
		System.out.println("** 在不同包的类(非子类)中,可访问的成员: **");
//		System.out.println("   Private member = " + o.nPrivate);
//		System.out.println("   Default member = " + o.nDefault);
//		System.out.println("  Protected member = " + o.nProtected);
		System.out.println("   Public member = "+o.nPublic);
	}
}

public class AccessControl2{
	public static void main(String[] args){
		Derived d = new Derived();
		d.access();
		AnotherPackage s = new AnotherPackage();
		s.access();
	}
}
