package pkg;
/**
    InitialTest.java
*/
class InitialTest {
	int varInstance;
	boolean bInst;
	static char c;
	float z;
	void setData(int intV, boolean boolV){
		varInstance = intV;
		boolV = bInst;  //bInst能自动初始化，所以不会出错。
		float x, y;
		z = x;    //编译时会出错：x尚未初始化。
		
	}
	public static void main(String args[]) {
		System.out.println(c);
		String s = new String("sss");
//		Math.PI
	}
}
