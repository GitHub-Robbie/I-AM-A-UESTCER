package linkedList;

import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class LLTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkedList<String> l = new LinkedList<>();
		ListIterator<String> iter = l.listIterator();
		
		iter.add("Bob");
		iter.add("Doug");
		iter.add("Frances");
		iter.add("Gloria");
		System.out.println(l);
		
		//set 方法用一个新元素取代调用 next 或 previous 方法返回的上一个元素; 
		ListIterator<String> iter2 = l.listIterator();

		//		String old = iter2.next();
//		iter2.set("AAA");
//		System.out.println(l);
		
		iter2.next();
		String old = iter2.previous();
		iter2.set("AAA");
		System.out.println(l);
		
		
	}

}
