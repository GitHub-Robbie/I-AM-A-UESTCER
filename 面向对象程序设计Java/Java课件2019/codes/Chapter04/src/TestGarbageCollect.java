/**
	Ô´³ÌÐò£ºTestGarbageCollect.java
*/
public class TestGarbageCollect{
	 public static void main(String[] args){
		Object a = new Float(12.1f);
		Object[] oa = new Object[1];
		oa[0] = a;
		a = null;
		oa[0] = null;
	}
}
