package arrayList;

import java.util.*;

/**
 * This program demonstrates the ArrayList class.
 */
public class ArrayListTest {
	public static void main(String[] args) {

		// fill the staff array list with three Employee objects
		// ArrayList<Employee> staff = new ArrayList<Employee>();
//		ArrayList staff = new ArrayList(); // allowed if we do not convert object to employee
		ArrayList<Employee> staff = new ArrayList<>();

		staff.add(new Employee("Carl Cracker", 75000, 1987, 12, 15));
		staff.add(new Employee("Harry Hacker", 50000, 1989, 10, 1));
		staff.add(new Employee("Tony Tester", 40000, 1990, 3, 15));
//		staff.add(new String("sss"));//not allowed for String

		// raise everyone's salary by 5%
		for (Employee e : staff)
			e.raiseSalary(5);

		// print out information about all Employee objects
		for (Employee e : staff)
			System.out.println("name=" + 
		e.getName() + ",salary=" + e.getSalary() + ",hireDay=" + e.getHireDay());
		
		//ArrayList size.
		System.out.println("List Size = " + staff.size());
		
		System.out.println("******************************************");
				
		staff.add(new Employee("001", 75000, 1987, 12, 15));
		staff.add(new Employee("002", 50000, 1989, 10, 1));
		staff.add(new Employee("003", 40000, 1990, 3, 15));
		
		//insert an object
		staff.add(2, new Employee("005", 40000, 1990, 3, 15));
		
		for (Employee e : staff)
			System.out.println("name=" + e.getName() + ",salary=" + e.getSalary() + ",hireDay=" + e.getHireDay());
		
		System.out.println("******************************************");
		
		//replace an object, similar to a[i] = b in array;
		staff.set(5, new Employee("007", 40000, 1990, 3, 15));
		
		
		for (Employee e : staff)
			System.out.println("name=" + e.getName() + ",salary=" + e.getSalary() + ",hireDay=" + e.getHireDay());
		
		
		System.out.println("******************************************");
		
		//remove an object.
		staff.remove(6);
		
		for (Employee e : staff)
			System.out.println("name=" + e.getName() + ",salary=" + e.getSalary() + ",hireDay=" + e.getHireDay());
		
		System.out.println("******************************************");
		
		// copy an ArrayList to an object array.
		Employee[] em = new Employee[staff.size()];
		staff.toArray(em);
		for (Employee e : em)
			System.out.println("name=" + e.getName() + ",salary=" + e.getSalary() + ",hireDay=" + e.getHireDay());
		
	}
}