/**
 * TestFIFOQueue.java
*/
class TestFIFOQueue{
	public static void main(String args[]){
//		Collection cVar = new Collection();//not allowed. 不能实例化一个接口。
		Collection cVar;//allowed. 可以声明接口的变量
		cVar = new FIFOQueue();//接口变量必须引用实现了接口的类对象
		Object o1 = new Object();
//		...
		cVar.add(o1);
//		...
	}
}
