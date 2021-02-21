package linkedList;

import java.util.*;

/**
 * This program demonstrates operations on linked lists.
 * 
 * @version 1.11 2012-01-26
 * @author Cay Horstmann
 */
public class LinkedListTest {
	public static void main(String[] args) {
		
		List<String> a = new LinkedList<>();
		a.add("Amy");
		a.add("Carl");
		a.add("Erica");

		List<String> b = new LinkedList<>();
		b.add("Bob");
		b.add("Doug");
		b.add("Frances");
		b.add("Gloria");

		// merge the words from b into a

		ListIterator<String> aIter = a.listIterator(); //listIterator
		Iterator<String> bIter = b.iterator();//Iterator
		
//		|ACE    |BDFG 
//		A|CE    |BDFG 
//		AB|CE   B|DFG

		while (bIter.hasNext()) { 
			if (aIter.hasNext()) 
				aIter.next();// skip one element, A|CE
			aIter.add(bIter.next()); //  bIter: B|DFG, aIter: AB|CE
		}

		System.out.println(a);

		// remove every second word from b

		bIter = b.iterator(); // new iterator, |BDFG
		while (bIter.hasNext()) {
			bIter.next(); // skip one element, B|DFG
			if (bIter.hasNext()) {
				bIter.next(); // skip next element, BD|FG
				bIter.remove(); // remove that element, B|FG
			}
		}

		System.out.println(b);

		// bulk operation: remove all words in b from a

		a.removeAll(b);

		System.out.println(a);
	}
}
