package genericTest;

import java.util.ArrayList;

public class GenericTest {
	public static void main(String[] args) {
		Manager[] topH;
//		ArrayList<Employee> r = ArrayList<Manager>;
		Manager ceo = new Manager("John", 10000.0, 1999, 1, 1);
		Manager cfo = new Manager("Jack", 20000.0, 1995, 2, 2);
		
		Manager[] managerBuddies = {ceo, cfo }; 
		Employee[] employeeBuddies = managerBuddies; // OK
		
		ArrayList<Manager> m = new ArrayList<>();
//		ArrayList<Employee> e = m;//not allowed
		
		// wildcard
		ArrayList<Manager> wm = new ArrayList<>();
//		String s ;
		ArrayList<? extends Employee> wb = wm; // OK
	}

}
