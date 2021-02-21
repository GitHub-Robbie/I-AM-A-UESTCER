import java.util.Random;

class test{
	static {System.out.print("hello");}
}


class StaticFieldInitTest {
	public static int nextId; 
	
	static
	{
	    Random generator = new Random();
		nextId = generator.nextInt(10000); 
	}
	
	void test() {
		
		test1();
	}
	
	static void test1() {
		
	}
	
	
	public static void main(String[] args){

		System.out.println("Random num: " + nextId);
		
//		test();
		
//		StaticFieldInitTest si = new StaticFieldInitTest();
//		
//		System.out.println("Random num: " + si.nextId);
		
	}
}
